/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:03 by panger            #+#    #+#             */
/*   Updated: 2023/12/06 15:14:29 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 1200
# define WIDTH	1200

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <math.h>

typedef struct	s_img_vars {
	void	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}			t_img_vars;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_img_vars	*img;
}				t_vars;

typedef struct	s_map_elem {
	int			x;
	int			y;
	int			z;
	int			u;
	int			v;
	__uint64_t	colors;
}	t_map_elem;

void		error_msg(char *str);

int			cross_close(t_vars *vars);
int			close_esc(int keycode, t_vars *vars);
t_vars		*create_window(t_map_elem ***map);
void		draw_line(t_vars *vars, t_map_elem *start, t_map_elem *stop);
void		transformations_img(t_map_elem ***map, t_vars *vars);
void		apply_scale(t_map_elem ***map);
void		apply_offset(t_map_elem ***map);
void		apply_isometric(t_map_elem ***map);
void	ft_resize(t_map_elem ***map, t_vars *vars);

char		*get_next_line(int fd);
int			ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strdupset(char const *s, int start, int stop);
char		*ft_strdup(const char *s);
char		*ft_stradd(char *s1, char *s2, int size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char *s, char *c);
char		*ft_strjoin(char *s1, char *s2);
char 		*read_file(char *path);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
char		***str_to_tab(char *map_str);
int			ft_atoi(const char *nptr);
__uint64_t	ft_atoi_colors(const char *nptr);
void		free_line(char **str);
t_map_elem	***map_parsing(char *path);
t_map_elem	***tab_to_map(char ***tab, int nb_lines, int line_len);

#endif