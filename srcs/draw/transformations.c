/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:07:26 by panger            #+#    #+#             */
/*   Updated: 2023/12/05 18:02:40 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	transformations_img(t_map_elem ***map, t_vars *vars)
{
	int	i;
	int	j;

	apply_scale(map);
	apply_offset(map);
	apply_isometric(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("at %d %d\n", i, j);
			if (map[i][j + 1])
			{
				printf("line 1 %d %d -> %d %d\n", map[i][j]->u, map[i][j]->v, map[i][j + 1]->u, map[i][j + 1]->v);
				printf("coords %d %d %d -> %d %d %d\n", map[i][j]->x, map[i][j]->y, map[i][j]->z, map[i][j + 1]->x, map[i][j + 1]->y, map[i][j + 1]->z);
				draw_line(vars, map[i][j]->u, map[i][j]->v, map[i][j + 1]->u, map[i][j + 1]->v);
			}
			if (map[i + 1])
			{
				printf("line 2 %d %d -> %d %d\n", map[i][j]->u, map[i][j]->v, map[i + 1][j]->u, map[i + 1][j]->v);
				printf("coords %d %d %d -> %d %d %d\n", map[i][j]->x, map[i][j]->y, map[i][j]->z, map[i + 1][j]->x, map[i + 1][j]->y, map[i + 1][j]->z);
				draw_line(vars, map[i][j]->u, map[i][j]->v, map[i + 1][j]->u, map[i + 1][j]->v);
				if (map[i + 1][j + 1])
				{
					printf("line 3 %d %d -> %d %d\n", map[i][j]->u, map[i][j]->v, map[i + 1][j + 1]->u, map[i + 1][j + 1]->v);
					printf("coords %d %d %d -> %d %d %d\n", map[i][j]->x, map[i][j]->y, map[i][j]->z, map[i + 1][j + 1]->x, map[i + 1][j + 1]->y, map[i + 1][j + 1]->z);
					draw_line(vars, map[i][j]->u, map[i][j]->v, map[i + 1][j + 1]->u, map[i + 1][j + 1]->v);
				}
			}
			j++;
		}
		i++;
	}	
}
