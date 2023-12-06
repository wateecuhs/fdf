/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:29:14 by panger            #+#    #+#             */
/*   Updated: 2023/12/06 15:18:58 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_resize_b(t_map_elem ***map, t_vars *vars);

void	ft_resize(t_map_elem ***map, t_vars *vars)
{
	int	i;
	int	j;
	int	min_x;
	int	max_x;

	max_x = -1;
	min_x = WIDTH + 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j]->u > max_x || max_x == -1)
				max_x = map[i][j]->u;
			if (map[i][j]->u < min_x || min_x == WIDTH + 1)
				min_x = map[i][j]->u;
			j++;
		}
		i++;
	}
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->u += (min_x * -1);
			j++;
		}
		i++;
	}
	ft_resize_b(map, vars);
}
void	ft_resize_b(t_map_elem ***map, t_vars *vars)
{
	int	i;
	int	j;
	int	min_y;
	int	max_y;

	max_y = -1;
	min_y = HEIGHT + 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j]->v < min_y || min_y == HEIGHT + 1)
				min_y = map[i][j]->v;
			j++;
		}
		i++;
	}
	i = 0;
	if (min_y > 0)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->v += (min_y * -1);
			j++;
		}
		i++;
	}
}