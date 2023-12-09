/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:27:29 by panger            #+#    #+#             */
/*   Updated: 2023/12/09 10:03:12 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


__uint32_t	packRGBA(t_colors color)
{
	printf("color %d %d %d %d\n", color.r, color.g, color.b, color.a);
	return (((uint32_t)color.r << 24) | ((uint32_t)color.g << 16)
		| ((uint32_t)color.b << 8) | (uint32_t)color.a);
}

float	get_distance(int z, t_coords z_range)
{
	float	ret;

	printf("z %d range %d %d\n", z, z_range.x, z_range.y);
	ret = (float)(z - z_range.x) / (float)(z_range.y - z_range.x);
	printf("RET %f\n", ret);
	return (ret);
}

int	get_color(t_map_elem map, t_coords z_range, t_mods *mods)
{
	t_colors	start;
	t_colors	stop;

	if (mods->use_preset == 0 || mods->color_preset == NULL
		|| (z_range.x == -1 && z_range.y == -1))
		return (map.input_colors);
	if (map.z < z_range.x + ((z_range.y - z_range.x) / 3))
	{
		start = assign_color(mods->color_preset->color1);
		stop = assign_color(mods->color_preset->color2);
	}
	else if (map.z < z_range.x + ((z_range.y - z_range.x) / 3) * 2)
	{
		start = assign_color(mods->color_preset->color2);
		stop = assign_color(mods->color_preset->color3);
	}
	else
	{
		start = assign_color(mods->color_preset->color3);
		stop = assign_color(mods->color_preset->color4);
	}
	printf("----------------\n");
	printf("%d %d %d %d\n", start.r, start.g, start.b, start.a);
	printf("%d %d %d %d\n", stop.r, stop.g, stop.b, stop.a);
	return (packRGBA(get_gradient(start, stop, get_distance(map.z, z_range))));
}
