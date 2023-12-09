/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:52:42 by panger            #+#    #+#             */
/*   Updated: 2023/12/09 11:22:12 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_elem	*make_values(char ***tab, int i, int j)
{
	t_map_elem	*tmp;
	char		**colors;

	tmp = (t_map_elem *)malloc(sizeof(t_map_elem) * 1);
	if (!tmp)
		return (NULL);
	tmp->x = j;
	tmp->y = i;
	tmp->z = ft_atoi(tab[i][j]);
	colors = ft_split(tab[i][j], ",");
	if (!colors)
		error_msg(NULL);
	if (colors[1] != 0)
		tmp->colors = ft_atoi_colors(colors[1]);
	else
		tmp->colors = 0xF2BAC9;
	free_line(colors);
	return (tmp);
}
