/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:06:53 by panger            #+#    #+#             */
/*   Updated: 2023/12/12 13:52:20 by panger           ###   ########.fr       */
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

int	loop(t_param *param)
{
	if (param->vars->mods->new_img == 1)
	{
		mlx_destroy_image(param->vars->mlx, param->vars->img->addr);
		create_image(param->map, param->vars);
		put_cmds_txt(param->vars);
		param->vars->mods->new_img = 0;
	}
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
	mlx_loop_hook(vars->mlx, loop, param);
	mlx_loop(vars->mlx);
	return (NULL);
}
