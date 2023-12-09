/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:13:19 by panger            #+#    #+#             */
/*   Updated: 2023/12/09 10:34:18 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_keybind2_2(int keycode, t_param *param);
void	parse_keybind1_1(int keycode, t_param *param);

void	parse_keybind1(int keycode, t_param *param)
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
	parse_keybind1_1(keycode, param);
	blackout_screen(param->vars);
	transformations_img(param->map, param->vars);
	mlx_put_image_to_window(param->vars->mlx,
		param->vars->win, param->vars->img->addr, 0, 0);
}

void	parse_keybind1_1(int keycode, t_param *param)
{
	if (keycode == 114 || keycode == 116)
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
	parse_keybind2_2(keycode, param);
	blackout_screen(param->vars);
	transformations_img(param->map, param->vars);
	mlx_put_image_to_window(param->vars->mlx,
		param->vars->win, param->vars->img->addr, 0, 0);
}

void	parse_keybind2_2(int keycode, t_param *param)
{
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
}

void	change_view(t_param *param)
{
	if (param->vars->mods->projection == 0)
		param->vars->mods->projection = 1;
	else if (param->vars->mods->projection == 1)
		param->vars->mods->projection = 2;
	else if (param->vars->mods->projection == 2)
		param->vars->mods->projection = 0;
	blackout_screen(param->vars);
	transformations_img(param->map, param->vars);
	mlx_put_image_to_window(param->vars->mlx,
		param->vars->win, param->vars->img->addr, 0, 0);
}
