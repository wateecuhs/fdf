/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:07:26 by panger            #+#    #+#             */
/*   Updated: 2023/12/08 14:56:26 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	transformations_img(t_map_elem ***map, t_vars *vars)
{
	int	i;
	int	j;

	apply_isometric(map, vars->mods);
	ft_resize(map, vars);
	printf("MODS FOR THIS RUN:\n%d %d %d %f %d %d %f\n", vars->mods->x_angle, vars->mods->y_angle, vars->mods->z_angle, vars->mods->z_coefficient, vars->mods->offset_u, vars->mods->offset_v, vars->mods->scale);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j + 1])
				draw_line(vars, map[i][j], map[i][j + 1]);
			if (map[i + 1])
			{
				draw_line(vars, map[i][j], map[i + 1][j]);
				if (map[i + 1][j + 1])
					draw_line(vars, map[i][j], map[i + 1][j + 1]);
			}
			j++;
		}
		i++;
	}	
}
