/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:07:26 by panger            #+#    #+#             */
/*   Updated: 2023/12/07 14:36:26 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	transformations_img(t_map_elem ***map, t_vars *vars)
{
	int	i;
	int	j;

	//apply_scale(map, vars->img->z_scale_quotient);
	apply_isometric(map, vars->img->z_scale_quotient);
	ft_resize(map, vars);
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
