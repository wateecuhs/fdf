/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:48 by panger            #+#    #+#             */
/*   Updated: 2023/12/08 15:06:52 by panger           ###   ########.fr       */
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
void	parse_keybind(int keycode, t_param *param)
{
	if (keycode == 122 || keycode == 120)
	{
		if (keycode == 122 && param->vars->mods->z_coefficient < 1)
			param->vars->mods->z_coefficient += 0.10;
		else if (keycode == 120 && param->vars->mods->z_coefficient > 0.1)
			param->vars->mods->z_coefficient -= 0.10;
		else
			return ;
	}
	else if (keycode == 114 || keycode == 116)
	{
		if (keycode == 114)
			param->vars->mods->x_angle -= 10;
		else if (keycode == 116)
			param->vars->mods->x_angle += 10;
		else
			return ;
		if (param->vars->mods->x_angle < 0)
			param->vars->mods->x_angle = 360 + param->vars->mods->x_angle;
		else if (param->vars->mods->x_angle > 360)
			param->vars->mods->x_angle = param->vars->mods->x_angle % 360;
	}
	blackout_screen(param->vars);
	transformations_img(param->map, param->vars);
	mlx_put_image_to_window(param->vars->mlx, param->vars->win, param->vars->img->addr, 0, 0);
}

void	parse_keybind2(int keycode, t_param *param)
{
	if (keycode == 102 || keycode == 103)
	{
		if (keycode == 102)
			param->vars->mods->y_angle -= 10;
		else if (keycode == 103)
			param->vars->mods->y_angle += 10;
		if (param->vars->mods->y_angle < 0)
			param->vars->mods->y_angle = 360 + param->vars->mods->y_angle;
		else if (param->vars->mods->y_angle > 360)
			param->vars->mods->y_angle = param->vars->mods->y_angle % 360;
	}
	if (keycode == 118 || keycode == 98)
	{
		if (keycode == 118)
			param->vars->mods->z_angle -= 10;
		else if (keycode == 98)
			param->vars->mods->z_angle += 10;
		if (param->vars->mods->z_angle < 0)
			param->vars->mods->z_angle = 360 + param->vars->mods->z_angle;
		else if (param->vars->mods->z_angle > 360)
			param->vars->mods->z_angle = param->vars->mods->z_angle % 360;
	}
	blackout_screen(param->vars);
	transformations_img(param->map, param->vars);
	mlx_put_image_to_window(param->vars->mlx, param->vars->win, param->vars->img->addr, 0, 0);
}

void	parse_keybind3(int keycode, t_param *param)
{
	if (keycode == 65361)
		param->vars->mods->offset_u -= 25;
	if (keycode == 65363)
		param->vars->mods->offset_u += 25;
	if (keycode == 65362)
		param->vars->mods->offset_v -= 25;
	if (keycode == 65364)
		param->vars->mods->offset_v += 25;
	blackout_screen(param->vars);
	transformations_img(param->map, param->vars);
	mlx_put_image_to_window(param->vars->mlx, param->vars->win, param->vars->img->addr, 0, 0);
}

void	parse_keybind4(int keycode, t_param *param)
{
	if (keycode == 111)
		param->vars->mods->scale *= 0.95;
	if (keycode == 112)
		param->vars->mods->scale *= 1.05;
	if (param->vars->mods->scale < 1 || param->vars->mods->scale > 1000)
		param->vars->mods->scale = get_scale(param->map);
	blackout_screen(param->vars);
	transformations_img(param->map, param->vars);
	mlx_put_image_to_window(param->vars->mlx, param->vars->win, param->vars->img->addr, 0, 0);
}

void	reset_mods(t_param *param)
{
	set_mods(param->map, param->vars->mods);
	blackout_screen(param->vars);
	transformations_img(param->map, param->vars);
	mlx_put_image_to_window(param->vars->mlx, param->vars->win, param->vars->img->addr, 0, 0);
}

int	key_hook(int keycode, t_param *param)
{
	printf("KEYBIND %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_image(param->vars->mlx, param->vars->img->addr);
		mlx_destroy_window(param->vars->mlx, param->vars->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 122 || keycode == 120 || keycode == 114 || keycode == 116)
		parse_keybind(keycode, param);
	if (keycode == 102 || keycode == 103 || keycode == 118 || keycode == 98)
		parse_keybind2(keycode, param);
	if (keycode == 65361 || keycode == 65363 || keycode == 65362 || keycode == 65364)
		parse_keybind3(keycode, param);
	if (keycode == 111 || keycode == 112)
		parse_keybind4(keycode, param);
	if (keycode == 113)
		reset_mods(param);
	return (0);
}
