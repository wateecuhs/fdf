/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:07:43 by panger            #+#    #+#             */
/*   Updated: 2023/12/09 10:05:25 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_colors	get_gradient(t_colors start, t_colors stop, float distance)
{
	t_colors	ret;
	ret.a = start.a + ((stop.a - start.a) * distance);
	ret.r = start.r + ((stop.r - start.r) * distance);
	printf("calc %d %d %f = %d\n", start.r, stop.r, distance, ret.r);
	ret.g = start.g + ((stop.g - start.g) * distance);
	printf("calc %d %d %f = %d\n", start.g, stop.g, distance, ret.g);
	ret.b = start.b + ((stop.b - start.b) * distance);
	printf("calc %d %d %f = %d\n", start.b, stop.b, distance, ret.b);
	return (ret);
}
