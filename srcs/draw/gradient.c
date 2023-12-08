/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:07:43 by panger            #+#    #+#             */
/*   Updated: 2023/12/08 22:10:44 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_colors	get_gradient(t_colors start, t_colors stop, int distance)
{
	t_colors	ret;

	ret.a = start.a + ((stop.a - start.a)/ 100 * distance);
	ret.r = start.r + ((stop.r - start.r)/ 100 * distance);
	ret.g = start.g + ((stop.g - start.g)/ 100 * distance);
	ret.b = start.b + ((stop.b - start.b)/ 100 * distance);
	return (ret);
}
