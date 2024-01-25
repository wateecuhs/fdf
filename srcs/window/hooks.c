/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:48 by panger            #+#    #+#             */
/*   Updated: 2024/01/25 13:27:01 by panger           ###   ########.fr       */
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

void	parse_keybind3(int keycode, t_param *param)
{
	if (keycode == 65361)
		param->vars->mods->inputs[0] = 1;
	if (keycode == 65363)
		param->vars->mods->inputs[1] = 1;
	if (keycode == 65362)
		param->vars->mods->inputs[2] = 1;
	if (keycode == 65364)
		param->vars->mods->inputs[3] = 1;

}
void	parse_keybind4(int keycode, t_param *param)
{
	if (keycode == 111)
		param->vars->mods->inputs[12] = 1;
	if (keycode == 112)
		param->vars->mods->inputs[13] = 1;
}

void	reset_mods(t_param *param)
{
	set_mods(param->map, param->vars->mods);
	param->vars->mods->new_img = 1;
}

int	key_hook(int keycode, t_param *param)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(param->vars->mlx, param->vars->img->addr);
		mlx_destroy_window(param->vars->mlx, param->vars->win);
		free_param(param);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 122 || keycode == 120 || keycode == 114 || keycode == 116)
		parse_keybind1(keycode, param);
	if (keycode == 102 || keycode == 103 || keycode == 118 || keycode == 98)
		parse_keybind2(keycode, param);
	if (keycode == 65361 || keycode == 65363
		|| keycode == 65362 || keycode == 65364)
		parse_keybind3(keycode, param);
	if (keycode == 111 || keycode == 112)
		parse_keybind4(keycode, param);
	if (keycode == 113)
		reset_mods(param);
	if (keycode == 32)
		change_view(param);
	return (0);
}
