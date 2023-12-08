/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_wip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:29:14 by panger            #+#    #+#             */
/*   Updated: 2023/12/08 14:46:36 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coords	get_offset(t_map_elem ***map, t_mods *mods)
{
	t_coords ret;
	t_map_elem	*middle;

	middle = find_center(map);
	ret.x = ((WIDTH / 2) - middle->u) + mods->offset_u;
	ret.y = ((HEIGHT / 2) - middle->v) + mods->offset_v;
	return (ret);
}

void	apply_offset(t_map_elem ***map, t_coords offset)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->u += offset.x;
			map[i][j]->v += offset.y;
			j++;
		}
		i++;
	}
}

void	ft_resize(t_map_elem ***map, t_vars *vars)
{
	t_mods	*mods;

	mods = vars->mods;
	apply_offset(map, get_offset(map, mods));
}
