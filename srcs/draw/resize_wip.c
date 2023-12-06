/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:29:14 by panger            #+#    #+#             */
/*   Updated: 2023/12/06 16:57:26 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coords	get_mins(t_map_elem ***map);
t_coords	get_max(t_map_elem ***map);

float	get_scale1(t_map_elem ***map, int len_dest, int len_src)
{
	float	scale;

	scale = (float)len_src / (float)len_dest;
	printf("%f\n", scale);
	return (scale);
}

void	apply_scale_u(t_map_elem ***map, float scale)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->u /= scale;
			j++;
		}
		i++;
	}
}

void	apply_scale_v(t_map_elem ***map, float scale)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->v /= scale;
			j++;
		}
		i++;
	}
}

t_coords	get_offset(t_coords min, t_coords min_borders)
{
	t_coords ret;

	ret.x = min_borders.x - min.x;
	ret.y = min_borders.y - min.y;
	return (ret);
}

int	apply_offset2(t_map_elem ***map, t_coords min, t_coords offset)
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
			map[i][j]->v += offset.x;
			j++;
		}
		i++;
	}
}

void	ft_resize(t_map_elem ***map, t_vars *vars)
{
	t_coords	min;
	t_coords	max;
	t_coords	min_borders;
	t_coords	hw;
	t_coords	scale;
	t_coords	max_borders;
	float			ratio;

	min = get_mins(map);
	max = get_max(map);
	ratio = ((float)max.x - (float)min.x) / ((float)max.y - (float)min.y);
	max_borders.x = (HEIGHT - (HEIGHT * 0.10));
	min_borders.x = (HEIGHT * 0.10);
	hw.x = max_borders.x - min_borders.x;
	max_borders.y = ((HEIGHT / ratio) - ((HEIGHT / ratio) * 0.10));
	min_borders.y = ((HEIGHT / ratio) * 0.10);
	hw.y = max_borders.y - min_borders.y;
	apply_scale_u(map, get_scale1(map, hw.x, max.x - min.x));
	apply_scale_u(map, get_scale1(map, hw.y, max.y - min.y));
	min = get_mins(map);
	max = get_max(map);
	apply_offset2(map, min, get_offset(min, min_borders));
}

t_coords	get_mins(t_map_elem ***map)
{
	int	i;
	int	j;
	t_coords ret;

	ret.x = WIDTH + 1;
	ret.y = HEIGHT + 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j]->u < ret.x || ret.x == WIDTH + 1)
				ret.x = map[i][j]->u;
			if (map[i][j]->v < ret.y || ret.y == HEIGHT + 1)
				ret.y = map[i][j]->v;
			j++;
		}
		i++;
	}
	return (ret);
}

t_coords	get_max(t_map_elem ***map)
{
	int	i;
	int	j;
	t_coords ret;

	ret.x = -1;
	ret.y = -1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j]->u > ret.x || ret.x == -1)
				ret.x = map[i][j]->u;
			if (map[i][j]->v > ret.y || ret.y == -1)
				ret.y = map[i][j]->v;
			j++;
		}
		i++;
	}
	return (ret);
}