/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:03 by panger            #+#    #+#             */
/*   Updated: 2023/12/04 15:36:25 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;

typedef struct	s_coords {
	int	x;
	int	y;
	int	z;
}	t_coords;

int		cross_close(t_vars *vars);
int		close_esc(int keycode, t_vars *vars);
t_vars	create_window(void);
int		draw_line(t_vars vars, int x, int y, int x_stop, int y_stop);

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strdupset(char const *s, int start, int stop);
char	*ft_strdup(const char *s);
char	*ft_stradd(char *s1, char *s2, int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char *s, char *c);

#endif