/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:48 by panger            #+#    #+#             */
/*   Updated: 2024/01/25 16:11:04 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cross_close(t_param *param)
{
	mlx_destroy_image(param->vars->mlx, param->vars->img->addr);
	mlx_destroy_window(param->vars->mlx, param->vars->win);
	free_param(param);
	exit(EXIT_SUCCESS);
	return (0);
}

void	parse_keybind1(int keycode, t_param *param, int val)
{
	if (keycode == 122)
		param->vars->mods->inputs[4] = val;
	if (keycode == 120)
		param->vars->mods->inputs[5] = val;
	if (keycode == 114)
		param->vars->mods->inputs[6] = val;
	if (keycode == 116)
		param->vars->mods->inputs[7] = val;
	if (keycode == 102)
		param->vars->mods->inputs[8] = val;
	if (keycode == 103)
		param->vars->mods->inputs[9] = val;
	if (keycode == 118)
		param->vars->mods->inputs[10] = val;
	if (keycode == 98)
		param->vars->mods->inputs[11] = val;
}

void	parse_keybind2(int keycode, t_param *param, int val)
{
	if (keycode == 65361)
		param->vars->mods->inputs[0] = val;
	if (keycode == 65363)
		param->vars->mods->inputs[1] = val;
	if (keycode == 65362)
		param->vars->mods->inputs[2] = val;
	if (keycode == 65364)
		param->vars->mods->inputs[3] = val;
	if (keycode == 111)
		param->vars->mods->inputs[12] = val;
	if (keycode == 112)
		param->vars->mods->inputs[13] = val;
}

void	change_view(t_param *param)
{
	if (param->vars->mods->projection == 0)
		param->vars->mods->projection = 1;
	else if (param->vars->mods->projection == 1)
		param->vars->mods->projection = 2;
	else if (param->vars->mods->projection == 2)
		param->vars->mods->projection = 0;
	param->vars->mods->new_img = 1;
}

int	key_press_hook(int keycode, t_param *param)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(param->vars->mlx, param->vars->img->addr);
		mlx_destroy_window(param->vars->mlx, param->vars->win);
		free_param(param);
		exit(EXIT_SUCCESS);
	}
	parse_keybind1(keycode, param, 1);
	parse_keybind2(keycode, param, 1);
	if (keycode == 113)
	{
		set_mods(param->map, param->vars->mods);
		param->vars->mods->new_img = 1;
	}
	if (keycode == 32)
		change_view(param);
	return (0);
}
