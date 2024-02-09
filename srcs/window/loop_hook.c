/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:03:29 by panger            #+#    #+#             */
/*   Updated: 2024/02/09 12:38:14 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_mods1(t_param *param)
{
	if (param->vars->mods->inputs[0] == 1)
	{
		param->vars->mods->offset_u += 10;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[1] == 1)
	{
		param->vars->mods->offset_u -= 10;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[2] == 1)
	{
		param->vars->mods->offset_v += 10;
		param->vars->mods->new_img = 1;
	}
}

void	update_mods2(t_param *param)
{
	if (param->vars->mods->inputs[3] == 1)
	{
		param->vars->mods->offset_v -= 10;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[4] == 1
		&& param->vars->mods->z_coefficient <= 1)
	{
		param->vars->mods->z_coefficient += 0.05;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[5] == 1
		&& param->vars->mods->z_coefficient > 0)
	{
		param->vars->mods->z_coefficient -= 0.05;
		param->vars->mods->new_img = 1;
	}
}

void	update_mods3(t_param *param)
{
	if (param->vars->mods->inputs[6] == 1)
	{
		param->vars->mods->x_angle -= 2;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[7] == 1)
	{
		param->vars->mods->x_angle += 2;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[8] == 1)
	{
		param->vars->mods->y_angle -= 2;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[9] == 1)
	{
		param->vars->mods->y_angle += 2;
		param->vars->mods->new_img = 1;
	}
}

void	update_mods4(t_param *param)
{
	if (param->vars->mods->inputs[10] == 1)
	{
		param->vars->mods->z_angle -= 2;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[11] == 1)
	{
		param->vars->mods->z_angle += 2;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[12] == 1)
	{
		param->vars->mods->scale *= 0.95;
		param->vars->mods->new_img = 1;
	}
	if (param->vars->mods->inputs[13] == 1)
	{
		param->vars->mods->scale *= 1.05;
		param->vars->mods->new_img = 1;
	}
}

int	loop(t_param *param)
{
	int	flag;

	update_mods1(param);
	update_mods2(param);
	update_mods3(param);
	update_mods4(param);
	if (param->vars->mods->new_img == 1)
	{
		mlx_destroy_image(param->vars->mlx, param->vars->img->addr);
		create_image(param->map, param->vars);
		put_cmds_txt(param->vars);
	}
	param->vars->mods->new_img = 0;
	return (0);
}
