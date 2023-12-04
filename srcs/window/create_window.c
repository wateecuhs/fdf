/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:06:53 by panger            #+#    #+#             */
/*   Updated: 2023/12/04 15:17:55 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_vars	create_window(void)
{
	t_vars	vars;
	int color = 0xF2BAC9;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Hello world!");
	if (!(vars.win))
		exit(EXIT_FAILURE);
	mlx_hook(vars.win, 2, 1L<<0, close_esc, &vars);
	mlx_hook(vars.win, 17, 1L<<0, cross_close, &vars);
	mlx_pixel_put(vars.mlx, vars.win, 500, 500, color);
	mlx_loop(vars.mlx);
	return (vars);
}