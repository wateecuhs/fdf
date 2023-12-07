/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:36:01 by panger            #+#    #+#             */
/*   Updated: 2023/12/07 14:20:59 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	blackout_screen(t_vars *vars)
{
	int			pixel;
	t_colors	colors;

	pixel = 0;
	colors = assign_color(0x000000);
	while (pixel < ((((HEIGHT - 1) * vars->img->line_bytes) + (HEIGHT - 1) * (vars->img->pixel_bits / 8)) - 4))
	{
		// /printf("pixel : %d %d %d %d\n", pixel, vars->img->line_bytes, vars->img->pixel_bits, (((HEIGHT * vars->img->line_bytes) + WIDTH * (vars->img->pixel_bits / 8)) - 4));
		draw_pixel(vars->img->buffer, pixel, colors, vars->img->endian);
		pixel++;
	}
}
//5764796
//5764795