/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:14 by panger            #+#    #+#             */
/*   Updated: 2024/01/26 10:52:58 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map_elem	***map;

	if (argc != 2)
	{
		write(2, "Wrong number of arguments.\n", 28);
		return (1);
	}
	map = map_parsing(argv[1]);
	if (!map)
		return (1);
	if (create_window(map) == NULL)
		return (1);
}
