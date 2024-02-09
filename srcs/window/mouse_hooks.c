/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:28:12 by panger            #+#    #+#             */
/*   Updated: 2024/02/09 12:02:54 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_mouse_down_hook(int button, int x, int y, t_param *param)
{
	if (button == 1)
	{
		param->vars->mods->inputs[14] = 1;
		param->vars->mods->mouse_press_x = x;
		param->vars->mods->mouse_press_y = y;
	}
	return (0);
}

int	on_mouse_up_hook(int button, int x, int y, t_param *param)
{
	t_coords	new_coords;

	if (button == 1)
		param->vars->mods->inputs[14] = 0;
	return (0);
}

int	on_mouse_move_hook(int x, int y, t_param *param)
{
	if (param->vars->mods->inputs[14] == 1)
	{
		param->vars->mods->x_angle -= ((x - param->vars->mods->mouse_press_x)
				* 360 / WIDTH);
		param->vars->mods->y_angle -= ((y - param->vars->mods->mouse_press_y)
				* 360 / HEIGHT);
		param->vars->mods->mouse_press_x = x;
		param->vars->mods->mouse_press_y = y;
	}
	return (0);
}
