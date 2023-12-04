/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:44:30 by panger            #+#    #+#             */
/*   Updated: 2023/12/04 15:23:16 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb == 1)
		return (1);
	while ((i * i) <= nb && i < 46341)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (i);
}

int	draw_line(t_vars vars, int x_start, int y_start, int x_stop, int y_stop)
{
	int	pixels;
	double	deltaX;
	double	deltaY;
	int color = 0xF2BAC9;
	double	startx;
	double	starty;

	deltaX = x_stop - x_start;
	deltaY = y_stop - y_start;
	pixels = ft_sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	startx = x_start;
	starty = y_start;
	while (pixels)
	{
		mlx_pixel_put(vars.mlx, vars.win, (int)startx, (int)starty, color);
		startx += deltaX;
		starty += deltaY;
		pixels--;
	}
	return (0);
}
