#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;

int	cross_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	close_esc(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}


int	main(void)
{
	t_vars	vars;
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	if (!(vars.win))
		exit(EXIT_FAILURE);
	mlx_hook(vars.win, 2, 1L<<0, close_esc, &vars);
	mlx_hook(vars.win, 17, 1L<<0, cross_close, &vars);
	vars.img = mlx_new_image(vars.mlx, 1920, 1080);
	buffer = mlx_get_data_addr(vars.img, &pixel_bits, &line_bytes, &endian);
	
	int color = 0xF2BAC9;

	if (pixel_bits != 32)
		color = mlx_get_color_value(vars.mlx, color);
	for(int y = 0; y < 1080; ++y)
	{
		for(int x = 0; x < 1920; ++x)
		{
			int pixel = (y * line_bytes) + (x * 4);
	
			if (endian == 1)        // Most significant (Alpha) byte first
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color) & 0xFF;
			}
			else if (endian == 0)   // Least significant (Blue) byte first
			{
				buffer[pixel + 0] = (color) & 0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
		}
	}
	color = 0xBAD7F2;
	for(int y = 0; y < 10; ++y)
	{
		for(int x = 1150; x < 1350; ++x)
		{
			int pixel = (y * line_bytes) + (x * 4);

			if (endian == 1)        // Most significant (Alpha) byte first
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color) & 0xFF;
			}
			else if (endian == 0)   // Least significant (Blue) byte first
			{
				buffer[pixel + 0] = (color) & 0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_loop(vars.mlx);
	
}
