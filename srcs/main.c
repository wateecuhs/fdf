/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:14 by panger            #+#    #+#             */
/*   Updated: 2023/12/08 22:14:59 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map_elem	***map;

	if (argc != 2)
	{
		write(2, "Wrong number of arguments.", 27);
		return (1);
	}
	map = map_parsing(argv[1]);
	create_window(map);
}
