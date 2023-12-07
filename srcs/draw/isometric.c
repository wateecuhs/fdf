/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:35:14 by panger            #+#    #+#             */
/*   Updated: 2023/12/07 14:38:02 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_isometric(t_map_elem ***map, float z_quotient)
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
			x = map[i][j]->x * scale;
			y = map[i][j]->y * scale;
			z = map[i][j]->z * (scale * z_quotient);
			map[i][j]->u = (1/sqrt(2)) * x + (1/sqrt(2)) * y;
			map[i][j]->v = -(1/sqrt(6)) * x + (1/sqrt(6)) * y - (2/sqrt(6)) * z;
			j++;
		}
		i++;
	}
}
