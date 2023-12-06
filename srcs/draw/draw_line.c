/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:44:30 by panger            #+#    #+#             */
/*   Updated: 2023/12/06 15:15:07 by panger           ###   ########.fr       */
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

void	draw_pixel(char *buffer, int pixel, int color, int endian)
{
	if (endian == 1)
	{
		buffer[pixel + 0] = (color >> 24);
		buffer[pixel + 1] = (color >> 16) & 0xFF;
		buffer[pixel + 2] = (color >> 8) & 0xFF;
		buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (endian == 0)
	{
		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
	}
}

void	draw_line(t_vars *vars, t_map_elem *start, t_map_elem *stop)
{
	int		pixels;
	double	deltaX;
	double	deltaY;
	double	startx;
	int		pixel;
	double	starty;

	deltaX = stop->u - start->u;
	deltaY = stop->v - start->v;
	pixels = ft_sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	startx = start->u;
	starty = start->v;
	while (pixels)
	{
		pixel = ((int)starty * vars->img->line_bytes) + ((int)startx * (vars->img->pixel_bits / 8));
		if (pixel >= 0 && pixel < 6960200)
		{
			draw_pixel(vars->img->buffer, pixel, stop->colors, vars->img->endian);
		}
		startx += deltaX;
		starty += deltaY;
		pixels--;
	}
}
