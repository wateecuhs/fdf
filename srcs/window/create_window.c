/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student->42->fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:06:53 by panger            #+#    #+#             */
/*   Updated: 2023/12/05 15:15:33 by panger           ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_map_elem ***map, t_vars *vars)
{
	vars->img->addr = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img->buffer = mlx_get_data_addr(vars->img->addr, &(vars->img->pixel_bits), &(vars->img->line_bytes), &(vars->img->endian));
	transformations_img(map, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->addr, 0, 0);
}

t_vars	*create_window(t_map_elem ***map)
{
	t_vars	*vars;
	t_param	*param;

	vars = (t_vars *)malloc(sizeof(t_vars) * 1);
	param = (t_param *)malloc(sizeof(t_param) * 1);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf - panger");
	if (!(vars->win))
		exit(EXIT_FAILURE);
	vars->img = (t_img_vars *)malloc(sizeof(t_img_vars) * 1);
	vars->img->z_scale_quotient = 0.25;
	create_image(map, vars);
	param->map = map;
	param->vars = vars;
	mlx_hook(vars->win, 17, 1L<<0, cross_close, vars);
	mlx_hook(vars->win, 2, 1L<<0, key_hook, param);
	mlx_loop(vars->mlx);
	return (vars);
}
