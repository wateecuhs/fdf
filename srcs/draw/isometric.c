/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:35:14 by panger            #+#    #+#             */
/*   Updated: 2023/12/07 17:20:42 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_isometric(t_map_elem ***map, t_mods *mods)
{
	int	i;
	int	j;
	int	max;
	int x;
	int y;
	int z;
	int	scale;

	scale = get_scale(map);
	i = 0;
	max = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			x = map[i][j]->x * 100;
			y = map[i][j]->y * 100;
			z = map[i][j]->z * (100 * mods->z_coefficient);
			//x = x;
			double temp_y = y * cos(mods->x_angle * (M_PI / 180)) - z * sin(mods->x_angle * (M_PI / 180));
			double temp_z = y * sin(mods->x_angle * (M_PI / 180)) + z * cos(mods->x_angle * (M_PI / 180));
			map[i][j]->u = (1/sqrt(2)) * x + (1/sqrt(2)) * temp_y;
			map[i][j]->v = -(1/sqrt(6)) * x + (1/sqrt(6)) * temp_y - (2/sqrt(6)) * temp_z;
			// map[i][j]->u = (1/sqrt(2)) * x + (1/sqrt(2)) * y;
			// map[i][j]->v = -(1/sqrt(6)) * x + (1/sqrt(6)) * y - (2/sqrt(6)) * z;
			j++;
		}
		i++;
	}
}
