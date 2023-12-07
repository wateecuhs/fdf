/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:48 by panger            #+#    #+#             */
/*   Updated: 2023/12/07 13:44:57 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cross_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->addr);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_param *param)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(param->vars->mlx, param->vars->img->addr);
		mlx_destroy_window(param->vars->mlx, param->vars->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 122)
	{
		if (param->vars->img->z_scale_quotient < 1)
		{
			param->vars->img->z_scale_quotient += 0.10;
			blackout_screen(param->vars);
			transformations_img(param->map, param->vars);
			mlx_put_image_to_window(param->vars->mlx, param->vars->win, param->vars->img->addr, 0, 0);
		}
	}
	else if (keycode == 120)
	{
		if (param->vars->img->z_scale_quotient > 0.1)
		{
		param->vars->img->z_scale_quotient -= 0.10;
		blackout_screen(param->vars);
		transformations_img(param->map, param->vars);
		mlx_put_image_to_window(param->vars->mlx, param->vars->win, param->vars->img->addr, 0, 0);
		}
	}
	return (0);
}
