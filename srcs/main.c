/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:14 by panger            #+#    #+#             */
/*   Updated: 2023/12/04 15:37:08 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_input(int fd)
{
	char	*s;
	char	**args;
	int		line;

	line = 0;
	s = get_next_line(fd);
	while (s != NULL)
	{
		
		s = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	
	create_window();
}