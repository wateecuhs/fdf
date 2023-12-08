/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:13:36 by panger            #+#    #+#             */
/*   Updated: 2023/12/08 16:21:04 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_theme_1(t_mods *mods)
{
	mods->color_preset->color1 = 0x8d5203;
	mods->color_preset->color2 = 0xe1c080;
	mods->color_preset->color3 = 0xc6eae6;
	mods->color_preset->color4 = 0x02655f;
}