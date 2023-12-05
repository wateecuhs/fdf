/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:29:18 by panger            #+#    #+#             */
/*   Updated: 2023/12/05 17:41:56 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	get_offset_x(t_map_elem ***map)
{
	int	j;
	int	i;
	int	max;

	i = 0;
	max = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j]->y > max)
				max = map[i][j]->y;
			j++;
		}
		i++;
	}
	return ((WIDTH - max) / 2);
}

int	get_offset_y(t_map_elem ***map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j]->x > max)
				max = map[i][j]->x;
			j++;
		}
		i++;
	}
	return ((HEIGHT - max) / 2);
}

void	apply_offset(t_map_elem ***map)
{
	int	i;
	int	j;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_x = get_offset_x(map);
	offset_y = get_offset_y(map);
	printf("offset %d %d\n", offset_x, offset_y);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->x += offset_x;
			map[i][j]->y += offset_y;
			j++;
		}
		i++;
	}
}
