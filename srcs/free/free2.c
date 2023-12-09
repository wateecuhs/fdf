/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:55:12 by panger            #+#    #+#             */
/*   Updated: 2023/12/09 11:18:33 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map_elem ***map);

void	free_tab_init(char ***str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free_line(str[i]);
		i++;
	}
	free(str);
}

void	free_param(t_param *param)
{
	free(param->vars->img);
	free(param->vars->mods);
	free(param->vars);
	free_map(param->map);
	free(param);
}

void	free_map(t_map_elem ***map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			free(map[i][j]);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}
