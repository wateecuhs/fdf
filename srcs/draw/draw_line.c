/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:44:30 by panger            #+#    #+#             */
/*   Updated: 2023/12/12 11:23:52 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(char *buffer, int pixel, t_colors color, int endian)
{
	if (endian == 1)
	{
		buffer[pixel + 0] = color.a;
		buffer[pixel + 1] = color.r;
		buffer[pixel + 2] = color.g;
		buffer[pixel + 3] = color.b;
	}
	else if (endian == 0)
	{
		buffer[pixel + 0] = color.b;
		buffer[pixel + 1] = color.g;
		buffer[pixel + 2] = color.r;
		buffer[pixel + 3] = color.a;
	}
}

t_colors_delta	get_color_delta(t_colors start, t_colors stop, int pixels)
{
	t_colors_delta	ret;

	ret.a = (float)(stop.a - start.a) / (float)pixels;
	ret.r = (float)(stop.r - start.r) / (float)pixels;
	ret.g = (float)(stop.g - start.g) / (float)pixels;
	ret.b = (float)(stop.b - start.b) / (float)pixels;
	return (ret);
}

t_colors	add_delta(t_colors color, t_colors_delta delta, int i)
{
	t_colors	ret;

	ret.a = color.a + (delta.a * i);
	ret.r = color.r + (delta.r * i);
	ret.g = color.g + (delta.g * i);
	ret.b = color.b + (delta.b * i);
	return (ret);
}

int	calc_pixel(t_f_coords start_coords, t_vars *vars)
{
	int	pixel;

	pixel = ((int)start_coords.y * vars->img->line_bytes)
		+ ((int)start_coords.x * (vars->img->pixel_bits / 8));
	return (pixel);
}

void	draw_line(t_vars *vars, t_map_elem *start, t_map_elem *stop, int i)
{
	int				pixels;
	t_f_coords		start_coords;
	t_f_coords		delta;
	t_colors		colors;
	t_colors_delta	colors_delta;

	delta = assign_f_xy(stop->u - start->u, stop->v - start->v);
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta = assign_f_xy(delta.x / pixels, delta.y / pixels);
	colors = assign_color(start->colors);
	colors_delta = get_color_delta(colors, assign_color(stop->colors), pixels);
	start_coords = assign_f_xy(start->u, start->v);
	while (pixels--)
	{
		if (start_coords.y > 0 && start_coords.y < HEIGHT
			&& start_coords.x > 0 && start_coords.x < R_WIDTH)
			draw_pixel(vars->img->buffer, calc_pixel(start_coords, vars),
				add_delta(colors, colors_delta, i), vars->img->endian);
		start_coords = assign_f_xy(start_coords.x
				+ delta.x, start_coords.y + delta.y);
		i++;
	}
}
