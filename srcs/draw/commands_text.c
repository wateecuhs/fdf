/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:27:29 by panger            #+#    #+#             */
/*   Updated: 2023/12/09 11:24:18 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_cmds_txt(t_vars *vars)
{
	mlx_set_font(vars->mlx, vars->win, "-*-*-*-*-*-*-15-*-*-*-*-*-*-*");
	mlx_string_put(vars->mlx, vars->win, WIDTH + 10, 200, 0xF2BAC9, "COMMANDS");
	mlx_string_put(vars->mlx, vars->win, WIDTH + 10,
		250, 0xF2BAC9, "Use arrows to move it around !");
	mlx_string_put(vars->mlx, vars->win, WIDTH + 10,
		270, 0xF2BAC9, "Press Space to change the projection !");
	mlx_string_put(vars->mlx, vars->win, WIDTH + 10,
		290, 0xF2BAC9, "R/T: Rotate around X axis");
	mlx_string_put(vars->mlx, vars->win, WIDTH + 10,
		310, 0xF2BAC9, "F/G: Rotate around Y axis");
	mlx_string_put(vars->mlx, vars->win, WIDTH + 10,
		330, 0xF2BAC9, "V/B: Rotate around Z axis");
	mlx_string_put(vars->mlx, vars->win, WIDTH + 10,
		350, 0xF2BAC9, "Z/X: Change Z-axis coefficient");
	mlx_string_put(vars->mlx, vars->win, WIDTH + 10,
		370, 0xF2BAC9, "O/P: Zoom in/out");
	mlx_string_put(vars->mlx, vars->win, WIDTH + 10,
		390, 0xF2BAC9, "Q  : Reset");
}
