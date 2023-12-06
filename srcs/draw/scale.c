/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:28:51 by panger            #+#    #+#             */
/*   Updated: 2023/12/06 18:02:00 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_scale(t_map_elem ***map)
{
	int	j;
	int	i;
	int	scale;

	i = 0;
	if (HEIGHT < WIDTH)
	{
		while (map[i])
			i++;
		scale = (HEIGHT) / (i - 1);
	}
	else
	{
		j = 0;
		while (map[0][j])
			j++;
		scale = (WIDTH) / (j - 1);
	}
	printf("SCALE %d\n", scale);
	return (scale);
}

void	apply_scale(t_map_elem ***map, float z_scale_quotient)
{
	int	i;
	int	j;
	int scale;

	i = 0;
	scale = get_scale(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->x *= scale;
			map[i][j]->y *= scale;
			map[i][j]->z *= (scale * z_scale_quotient);
			j++;
		}
		i++;
	}
}