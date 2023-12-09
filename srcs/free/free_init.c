/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:57:03 by panger            #+#    #+#             */
/*   Updated: 2023/12/09 11:22:19 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_line(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_up_to(char ***str, int limit)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < (unsigned int)limit)
	{
		free_line(str[i]);
		i++;
	}
	free(str);
}

void	free_line_map(t_map_elem **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_line_map_up_to(t_map_elem **str, int limit)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < (unsigned int)limit)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_up_to_map(t_map_elem ***str, int limit)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < (unsigned int)limit)
	{
		free_line_map(str[i]);
		i++;
	}
	free(str);
}
