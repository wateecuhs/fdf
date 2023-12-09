/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:25:28 by panger            #+#    #+#             */
/*   Updated: 2023/12/09 11:22:05 by panger           ###   ########.fr       */
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
	if (!map_tab)
		perror("fdf: malloc failed");
	nb_lines = 0;
	while (map_tab[nb_lines])
	{
		lines_len = 0;
		while (map_tab[nb_lines][lines_len])
			lines_len++;
		nb_lines++;
	}
	map = tab_to_map(map_tab, nb_lines, lines_len);
	if (!map)
		perror("fdf: malloc failed");
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
		{
			free(map);
			error_msg(path);
		}
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
		return (free_line(map_lines), NULL);
	i = 0;
	while (map_lines[i])
	{
		map[i] = ft_split(map_lines[i], " ");
		if (!(map[i]))
			return (free_up_to(map, i), NULL);
		i++;
	}
	map[i] = 0;
	free_line(map_lines);
	free(map_str);
	return (map);
}

t_map_elem	**tab_to_map_loop(char ***tab, t_map_elem ***map, int i, int len)
{
	int	j;

	j = 0;
	map[i] = (t_map_elem **)malloc(sizeof(t_map_elem *) * (len + 1));
	if (!(map[i]))
		return (free_up_to_map(map, i), NULL);
	while (tab[i][j])
	{
		map[i][j] = make_values(tab, i, j);
		if (!(map[i][j]))
			return (free_line_map_up_to(map[i], j),
				free_up_to_map(map, i), NULL);
		j++;
	}
	map[i][j] = 0;
	return (map[i]);
}

t_map_elem	***tab_to_map(char ***tab, int nb_lines, int line_len)
{
	t_map_elem	***map;
	int			i;

	i = 0;
	map = (t_map_elem ***)malloc(sizeof(t_map_elem **) * (nb_lines + 1));
	if (!map)
		return (NULL);
	while (tab[i])
	{
		if (tab_to_map_loop(tab, map, i, line_len) == NULL)
		{
			free_tab_init(tab);
			return (NULL);
		}
		i++;
	}
	free_tab_init(tab);
	map[i] = 0;
	return (map);
}
