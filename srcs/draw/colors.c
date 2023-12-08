/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:13:36 by panger            #+#    #+#             */
/*   Updated: 2023/12/08 17:21:26 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color_preset	set_theme_1(void)
{
	t_color_preset	ret;

	ret.color1 = 0x8d5203;
	ret.color2 = 0xe1c080;
	ret.color3 = 0xc6eae6;
	ret.color4 = 0x02655f;
	return (ret);
}
