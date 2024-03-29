/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:07:26 by panger            #+#    #+#             */
/*   Updated: 2024/02/09 12:00:59 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transformations_img(t_map_elem ***map, t_vars *vars)
{
	int	i;
	int	j;

	apply_isometric(map, vars->mods);
	ft_resize(map, vars);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j + 1])
				draw_line(vars, map[i][j], map[i][j + 1], 0);
			if (map[i + 1] && j < ft_linelen(map[i + 1]))
			{
				draw_line(vars, map[i][j], map[i + 1][j], 0);
				if (map[i + 1][j + 1])
					draw_line(vars, map[i][j], map[i + 1][j + 1], 0);
			}
			j++;
		}
		i++;
	}
}
