/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:47:03 by panger            #+#    #+#             */
/*   Updated: 2023/12/08 17:52:29 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 	1200
# define WIDTH		1200
# define R_WIDTH	1600
# define M_PI		3.14159265358979323846

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <stdint.h>

typedef struct s_img_vars {
	void	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	float	z_scale_quotient;
}			t_img_vars;

typedef struct color_preset {
	__uint32_t	color1;
	__uint32_t	color2;
	__uint32_t	color3;
	__uint32_t	color4;
}			t_color_preset;

typedef struct s_mods {
	float			z_coefficient;
	int				x_angle;
	int				y_angle;
	int				z_angle;
	int				offset_u;
	int				offset_v;
	float			scale;
	t_color_preset	*color_preset;
}			t_mods;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_img_vars	*img;
	t_mods		*mods;
}				t_vars;

typedef struct s_map_elem {
	int			x;
	int			y;
	int			z;
	int			u;
	int			v;
	__uint32_t	colors;
}	t_map_elem;

typedef struct s_coords {
	int	x;
	int	y;
}			t_coords;

typedef struct s_colors {
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}			t_colors;

typedef struct s_colors_delta {
	float	a;
	float	r;
	float	g;
	float	b;
}			t_colors_delta;

typedef struct s_f_coords {
	float	x;
	float	y;
}			t_f_coords;

typedef struct s_param {
	t_vars		*vars;
	t_map_elem	***map;
}			t_param;

void			error_msg(char *str);
int				cross_close(t_vars *vars);
int				key_hook(int keycode, t_param *param);
t_vars			*create_window(t_map_elem ***map);
void			draw_line(t_vars *vars, t_map_elem *start, t_map_elem *stop);
void			transformations_img(t_map_elem ***map, t_vars *vars);
void			apply_scale(t_map_elem ***map, float z_scale_quotient);
void			apply_offset(t_map_elem ***map, t_coords offset);
void			apply_isometric(t_map_elem ***map, t_mods *mods);
void			ft_resize(t_map_elem ***map, t_vars *vars);
t_f_coords		assign_f_xy(float x, float y);
t_coords		assign_xy(int x, int y);
t_colors		assign_color(__uint32_t color);
void			create_image(t_map_elem ***map, t_vars *vars);
void			draw_pixel(char *buffer, int pixel, t_colors color, int endian);
int				get_scale(t_map_elem ***map);
char			*get_next_line(int fd);
int				ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strdupset(char const *s, int start, int stop);
char			*ft_strdup(const char *s);
char			*ft_stradd(char *s1, char *s2, int size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char *s, char *c);
char			*ft_strjoin(char *s1, char *s2);
char			*read_file(char *path);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			***str_to_tab(char *map_str);
int				ft_atoi(const char *nptr);
uint32_t		ft_atoi_colors(const char *nptr);
void			free_line(char **str);
t_map_elem		***map_parsing(char *path);
t_map_elem		***tab_to_map(char ***tab, int nb_lines, int line_len);
void			blackout_screen(t_vars *vars);
void			put_cmds_txt(t_vars *vars);
t_map_elem		*find_center(t_map_elem ***map);
t_coords		apply_mods(t_map_elem map, t_mods *mods, t_coords offset);
void			set_mods(t_map_elem ***map, t_mods *mods);
t_color_preset	set_theme_1(void);
void			parse_keybind1(int keycode, t_param *param);
void			parse_keybind2(int keycode, t_param *param);

#endif