/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:07:10 by panger            #+#    #+#             */
/*   Updated: 2023/12/08 17:55:14 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_elem	rotation_x(t_map_elem map, int angle)
{
	double	temp_x;
	double	temp_y;

	temp_x = (map.x * cos(angle * (M_PI / 180)))
		- (map.y * sin(angle * (M_PI / 180)));
	temp_y = (map.x * sin(angle * (M_PI / 180)))
		+ (map.y * cos(angle * (M_PI / 180)));
	map.x = temp_x;
	map.y = temp_y;
	return (map);
}

t_map_elem	rotation_y(t_map_elem map, int angle)
{
	double	temp_x;
	double	temp_z;

	temp_x = (map.x * cos(angle * (M_PI / 180)))
		+ (map.z * sin(angle * (M_PI / 180)));
	temp_z = (-1 * (map.x) * sin(angle * (M_PI / 180)))
		+ (map.z * cos(angle * (M_PI / 180)));
	map.x = temp_x;
	map.z = temp_z;
	return (map);
}

t_map_elem	rotation_z(t_map_elem map, int angle)
{
	double	temp_y;
	double	temp_z;

	temp_y = map.y * cos(angle * (M_PI / 180))
		- map.z * (sin(angle * (M_PI / 180)));
	temp_z = map.y * sin(angle * (M_PI / 180))
		+ map.z * (cos(angle * (M_PI / 180)));
	map.y = temp_y;
	map.z = temp_z;
	return (map);
}

t_coords	apply_mods(t_map_elem map, t_mods *mods, t_coords offset)
{
	t_coords	ret;

	map.x *= mods->scale;
	map.y *= mods->scale;
	map.z *= mods->scale * mods->z_coefficient;
	if (mods->x_angle != 0)
		map = rotation_x(map, mods->x_angle);
	if (mods->y_angle != 0)
		map = rotation_y(map, mods->y_angle);
	if (mods->z_angle != 0)
		map = rotation_z(map, mods->z_angle);
	map.x += (offset.x * mods->scale);
	map.y += (offset.y * mods->scale);
	ret.x = (1 / sqrt(2)) * map.x + (1 / sqrt(2)) * map.y;
	ret.y = -(1 / sqrt(6)) * map.x
		+ (1 / sqrt(6)) * map.y - (2 / sqrt(6)) * map.z;
	return (ret);
}
