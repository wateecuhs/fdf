/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:35:14 by panger            #+#    #+#             */
/*   Updated: 2023/12/09 10:01:35 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	offset_map(t_map_elem ***map)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	k = 0;
	while (map[k])
	{
		l = 0;
		while (map[k][l])
		{
			map[k][l]->x -= ((j - 1) / 2);
			map[k][l]->y -= ((i - 1) / 2);
			l++;
		}
		k++;
	}
}

t_coords	offset_map_back(t_map_elem ***map)
{
	t_coords	ret;
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	ret.x = ((j - 1) / 2);
	ret.y = ((i - 1) / 2);
	return (ret);
}

t_coords	get_z_range(t_map_elem ***map)
{
	int			i;
	int			j;
	t_coords	z_range;

	z_range = assign_xy(-1, -1);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (z_range.x == -1 && z_range.y == -1)
				z_range = assign_xy(map[i][j]->z, map[i][j]->z);
			if (map[i][j]->z < z_range.x)
				z_range.x = map[i][j]->z;
			if (map[i][j]->z > z_range.y)
				z_range.y = map[i][j]->z;
			j++;
		}
		i++;
	}
	return (z_range);
}

void	apply_isometric(t_map_elem ***map, t_mods *mods)
{
	int			i;
	int			j;
	t_coords	offset;
	t_coords	z_range;
	t_coords	uv;

	offset_map(map);
	offset = offset_map_back(map);
	z_range = get_z_range(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->colors = get_color(*map[i][j], z_range, mods);
			uv = apply_mods(*map[i][j], mods, offset);
			map[i][j]->u = uv.x;
			map[i][j]->v = uv.y;
			j++;
		}
		i++;
	}
}
