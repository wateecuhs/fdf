/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:49:48 by panger            #+#    #+#             */
/*   Updated: 2023/12/07 12:40:05 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coords	assign_xy(int x, int y)
{
	t_coords	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_f_coords	assign_f_xy(float x, float y)
{
	t_f_coords	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_colors	assign_color(__uint32_t color)
{
	t_colors	ret;

	ret.a = color >> 24;
	ret.r = color >> 16;
	ret.g = color >> 8;
	ret.b = color >> 0;

	return (ret);
}
