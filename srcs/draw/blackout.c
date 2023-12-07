/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:36:01 by panger            #+#    #+#             */
/*   Updated: 2023/12/07 15:04:36 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	blackout_screen(t_vars *vars)
{
	int			pixel;
	t_colors	colors;

	pixel = 0;
	colors = assign_color(0x000000);
	while (pixel < ((((HEIGHT - 1) * vars->img->line_bytes) + (HEIGHT - 1) * (vars->img->pixel_bits / 8))))
	{
		draw_pixel(vars->img->buffer, pixel, colors, vars->img->endian);
		pixel++;
	}
}
