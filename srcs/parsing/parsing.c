/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:25:28 by panger            #+#    #+#             */
/*   Updated: 2023/12/05 17:20:35 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_elem	***map_parsing(char *path)
{
	t_map_elem	***map;
	char		*map_str;
	char		***map_tab;
	int			nb_lines;
	int			lines_len;

	map_str = read_file(path);
	map_tab = str_to_tab(map_str);
	nb_lines = 0;
	while (map_tab[nb_lines])
	{
		lines_len = 0;
		while (map_tab[nb_lines][lines_len])
			lines_len++;
		nb_lines++;
	}
	map = tab_to_map(map_tab, nb_lines, lines_len);
	return (map);
}

char	*read_file(char *path)
{
	char	*map;
	char	*tmp;
	int		fd;

	map = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_msg(path);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		map = ft_strjoin(map, tmp);
		free(tmp);
		if (!map)
			error_msg(path);
		tmp = get_next_line(fd);
	}
	return (map);
}

char	***str_to_tab(char *map_str)
{
	char	**map_lines;
	char	***map;
	int		i;

	map_lines = ft_split(map_str, "\n");
	if (!map_lines)
		return (NULL);
	i = 0;
	while (map_lines[i])
		i++;
	map = (char ***)malloc(sizeof(char **) * (i + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (map_lines[i])
	{
		map[i] = ft_split(map_lines[i], " ");
		i++;
	}
	map[i] = 0;
	free_line(map_lines);
	free(map_str);
	return (map);
}

t_map_elem	*make_values(char ***tab, int i, int j)
{
	t_map_elem *tmp;
	char		**colors;

	tmp = (t_map_elem *)malloc(sizeof(t_map_elem) * 1);
	tmp->x = i;
	tmp->y = j;
	tmp->z = ft_atoi(tab[i][j]);
	colors = ft_split(tab[i][j], ",");
	if (!colors)
		error_msg(NULL);
	if (colors[1] != 0)
		tmp->colors = ft_atoi_colors(colors[1]);
	else
		tmp->colors = 0xF2BAC9;
	free_line(colors);
	return (tmp);
}

t_map_elem	***tab_to_map(char ***tab, int nb_lines, int line_len)
{
	t_map_elem	***map;
	int			i;
	int			j;

	i = 0;
	map = (t_map_elem ***)malloc(sizeof(t_map_elem **) * (nb_lines + 1));
	while (tab[i])
	{
		j = 0;
		map[i] = (t_map_elem **)malloc(sizeof(t_map_elem *) * (line_len + 1));
		while (tab[i][j])
		{
			map[i][j] = make_values(tab, i, j);
			j++;
		}
		free_line(tab[i]);
		map[i][j] = 0;
		i++;
	}
	free(tab);
	map[i] = 0;
	return (map);
}
