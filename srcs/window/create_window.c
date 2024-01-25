/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:06:53 by panger            #+#    #+#             */
/*   Updated: 2024/01/25 13:26:22 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_mods(t_map_elem ***map, t_mods *mods)
{
	mods->z_coefficient = 0.25;
	mods->x_angle = 0;
	mods->y_angle = 0;
	mods->z_angle = 0;
	mods->offset_v = 0;
	mods->offset_u = 0;
	mods->scale = get_scale(map);
	mods->projection = 0;
	for (int i = 0; i < 8; i++)
		mods->inputs[i] = 0;
}

void	create_image(t_map_elem ***map, t_vars *vars)
{
	vars->img->addr = mlx_new_image(vars->mlx, R_WIDTH, HEIGHT);
	vars->img->buffer = mlx_get_data_addr(vars->img->addr,
			&(vars->img->pixel_bits),
			&(vars->img->line_bytes),
			&(vars->img->endian));
	transformations_img(map, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->addr, 0, 0);
}

t_vars	*init_window(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars) * 1);
	if (!vars)
		return (NULL);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, R_WIDTH, HEIGHT, "fdf - panger");
	if (!(vars->win))
		exit(EXIT_FAILURE);
	vars->img = (t_img_vars *)malloc(sizeof(t_img_vars) * 1);
	if (!(vars->img))
		return (free(vars), NULL);
	vars->mods = (t_mods *)malloc(sizeof(t_mods));
	if (!(vars->mods))
		return (free(vars->img), free(vars), NULL);
	return (vars);
}

void	update_mods(t_param *param)
{
	if (param->vars->mods->inputs[0] == 1)
		param->vars->mods->offset_u += 10;
	if (param->vars->mods->inputs[1] == 1)
		param->vars->mods->offset_u -= 10;
	if (param->vars->mods->inputs[2] == 1)
		param->vars->mods->offset_v += 10;
	if (param->vars->mods->inputs[3] == 1)
		param->vars->mods->offset_v -= 10;
	if (param->vars->mods->inputs[4] == 1 && param->vars->mods->z_coefficient <= 1)
		param->vars->mods->z_coefficient += 0.05;
	if (param->vars->mods->inputs[5] == 1 && param->vars->mods->z_coefficient > 0)
		param->vars->mods->z_coefficient -= 0.05;
	if (param->vars->mods->inputs[6] == 1)
		param->vars->mods->x_angle -= 2;
	if (param->vars->mods->inputs[7] == 1)
		param->vars->mods->x_angle += 2;
	if (param->vars->mods->inputs[8] == 1)
		param->vars->mods->y_angle -= 2;
	if (param->vars->mods->inputs[9] == 1)
		param->vars->mods->y_angle += 2;
	if (param->vars->mods->inputs[10] == 1)
		param->vars->mods->z_angle -= 2;
	if (param->vars->mods->inputs[11] == 1)
		param->vars->mods->z_angle += 2;
	if (param->vars->mods->inputs[12] == 1)
		param->vars->mods->scale *= 0.95;
	if (param->vars->mods->inputs[13] == 1)
		param->vars->mods->scale *= 1.05;
}

int	loop(t_param *param)
{
	update_mods(param);
	mlx_destroy_image(param->vars->mlx, param->vars->img->addr);
	create_image(param->map, param->vars);
	put_cmds_txt(param->vars);
	param->vars->mods->new_img = 0;
	return (0);
}

int	key_up(int keycode, t_param *param)
{
	if (keycode == 65361)
		param->vars->mods->inputs[0] = 0;
	if (keycode == 65363)
		param->vars->mods->inputs[1] = 0;
	if (keycode == 65362)
		param->vars->mods->inputs[2] = 0;
	if (keycode == 65364)
		param->vars->mods->inputs[3] = 0;
	if (keycode == 122)
		param->vars->mods->inputs[4] = 0;
	if (keycode == 120)
		param->vars->mods->inputs[5] = 0;
	if (keycode == 114)
		param->vars->mods->inputs[6] = 0;
	if (keycode == 116)
		param->vars->mods->inputs[7] = 0;
	if (keycode == 102)
		param->vars->mods->inputs[8] = 0;
	if (keycode == 103)
		param->vars->mods->inputs[9] = 0;
	if (keycode == 118)
		param->vars->mods->inputs[10] = 0;
	if (keycode == 119)
		param->vars->mods->inputs[11] = 0;
	if (keycode == 111)
		param->vars->mods->inputs[12] = 0;
	if (keycode == 112)
		param->vars->mods->inputs[13] = 0;
	return (0);
}

t_vars	*create_window(t_map_elem ***map)
{
	t_vars	*vars;
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param) * 1);
	if (!param)
		return (free_map(map), NULL);
	vars = init_window();
	if (!vars)
		return (free_map(map), free(param), NULL);
	set_mods(map, vars->mods);
	create_image(map, vars);
	put_cmds_txt(vars);
	param->map = map;
	param->vars = vars;
	mlx_hook(vars->win, 17, 1L << 0, cross_close, param);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, param);
	mlx_hook(vars->win, 3, (1L<<1), key_up, param);
	mlx_loop_hook(vars->mlx, loop, param);
	mlx_loop(vars->mlx);
	return (NULL);
}
