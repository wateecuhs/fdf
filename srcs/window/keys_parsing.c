/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:13:19 by panger            #+#    #+#             */
/*   Updated: 2024/01/25 13:24:31 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_keybind2_2(int keycode, t_param *param);
// void	parse_keybind1_1(int keycode, t_param *param);

void	parse_keybind1(int keycode, t_param *param)
{
	if (keycode == 122)
		param->vars->mods->inputs[4] = 1;
	if (keycode == 120)
		param->vars->mods->inputs[5] = 1;
	if (keycode == 114)
		param->vars->mods->inputs[6] = 1;
	if (keycode == 116)
		param->vars->mods->inputs[7] = 1;
}

void	parse_keybind2(int keycode, t_param *param)
{
	if (keycode == 102)
		param->vars->mods->inputs[8] = 1;
	if (keycode == 103)
		param->vars->mods->inputs[9] = 1;
	if (keycode == 118)
		param->vars->mods->inputs[10] = 1;
	if (keycode == 119)
		param->vars->mods->inputs[11] = 1;
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
