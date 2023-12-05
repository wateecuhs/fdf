/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:44:30 by panger            #+#    #+#             */
/*   Updated: 2023/12/05 18:56:52 by panger           ###   ########.fr       */
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


int	draw_line(t_vars *vars, int x_start, int y_start, int x_stop, int y_stop)
{
	int		pixels;
	double	deltaX;
	double	deltaY;
	int 	color = 0xF2BAC9;
	double	startx;
	int		pixel;
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
		pixel = ((int)starty * vars->img->line_bytes) + ((int)startx * (vars->img->pixel_bits / 8));
		printf("PIXEL CRASHING IT %d\n", pixel);
		if (pixel >= 0 && pixel < 4829188)
		{
			if (vars->img->endian == 1)
			{
				vars->img->buffer[pixel + 0] = (color >> 24);
				vars->img->buffer[pixel + 1] = (color >> 16) & 0xFF;
				vars->img->buffer[pixel + 2] = (color >> 8) & 0xFF;
				vars->img->buffer[pixel + 3] = (color) & 0xFF;
			}
			else if (vars->img->endian == 0)
			{
				vars->img->buffer[pixel + 0] = (color) & 0xFF;
				vars->img->buffer[pixel + 1] = (color >> 8) & 0xFF;
				vars->img->buffer[pixel + 2] = (color >> 16) & 0xFF;
				vars->img->buffer[pixel + 3] = (color >> 24);
			}
		}
		startx += deltaX;
		starty += deltaY;
		pixels--;
	}
	return (0);
}
