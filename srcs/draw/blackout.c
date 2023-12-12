/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:36:01 by panger            #+#    #+#             */
/*   Updated: 2023/12/12 11:25:56 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	blackout_screen(t_vars *vars)
{
	int			pixel;
	int			pixelx;
	int			pixely;
	t_colors	colors;

	pixel = 0;
	colors = assign_color(0x000000);
	pixely = 0;
	while (pixely <= HEIGHT)
	{
		pixelx = 0;
		while (pixelx <= R_WIDTH)
		{
			pixel = pixely * vars->img->line_bytes
				+ pixelx * (vars->img->pixel_bits / 8);
			draw_pixel(vars->img->buffer, pixel, colors, vars->img->endian);
			pixelx++;
		}
		pixely++;
	}
}
