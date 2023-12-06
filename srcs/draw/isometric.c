/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:35:14 by panger            #+#    #+#             */
/*   Updated: 2023/12/06 13:59:58 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define PI 3.14159265358979323846
void	apply_isometric(t_map_elem ***map)
{
	int	i;
	int	j;
	int	max;
	int x;
	int y;
	int z;
	int alpha;

	i = 0;
	max = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			alpha = 45 * PI / 180.0;
			x = map[i][j]->x;
			y = map[i][j]->y;
			z = map[i][j]->z;
			map[i][j]->u = (1/sqrt(2)) * x + (1/sqrt(2)) * y;
			map[i][j]->v = -(1/sqrt(6)) * x + (1/sqrt(6)) * y - (2/sqrt(6)) * z;
			// map[i][j]->u = (1/sqrt(2)) * x - (1/sqrt(2)) * y;
			// map[i][j]->v = (1/sqrt(6)) * x + (1/sqrt(6)) * y - (2/sqrt(6)) * z;
			j++;
		}
		i++;
	}
}
