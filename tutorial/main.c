/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:58:17 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/20 18:41:16 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>

// GONTJAROW - REMIX

/* typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 360, "Hello world!");
	img.img = mlx_new_image(mlx, 640, 360);

	char *buffer = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	img.line_length /= 4;

	int color = 0xABCDEF;

	for(int y = 0; y < 360; ++y)
	for(int x = 0; x < 640; ++x)
	{
		buffer[(y * img.line_length) + x] = color;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
} */

// GONTJAROW 

/* int	main(void)
{
	int pixel_bits;
	int line_bytes;
	int endian;

	void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Create Image");
    void *image = mlx_new_image(mlx, 640, 360);

    char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	line_bytes /= 4;

	int color = 0xABCDEF;

	for(int y = 0; y < 360; ++y)
	for(int x = 0; x < 640; ++x)
	{
		buffer[(y * line_bytes) + x] = color;
	}

	mlx_put_image_to_window(mlx, win, image, 0, 0);
    mlx_loop(mlx);
} */

// INT TO RGB

/* 
int get_a(int argb)
{
    return ((argb >> 24) & 0xFF);
}

int get_r(int argb)
{
    return ((argb >> 16) & 0xFF);
}

int get_g(int argb)
{
    return ((argb >> 8) & 0xFF);
}

int get_b(int argb)
{
    return (argb & 0xFF);
}

int	main(void)
{
	int	result;

	result = get_r(16777215);
	printf("%d", result);
	return (0);
} */

// RGB to INT

/* int create_argb(int a, int r, int g, int b)
{
    return (a << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	int	result;

	result = create_argb(0, 171, 205, 239);
	printf("%d", result);
	return (0);
} */

// HEX to INT

/* int	main(void)
{
	void	*mlx_ptr;
	int 	color;
	unsigned int	result;

	color = 0xABCDEF;
	mlx_ptr = mlx_init();
	result = mlx_get_color_value(mlx_ptr, color);
	printf("%x", result);
	return (0);
} */

// REACTIVE

/* typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;
 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}
 
int main(void)
{
	t_data data;
 
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
 
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
 
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
} */

// 42 DOCS HOOKS

/* typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
} */

// 42 DOCS EVENTS

/* typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
} */

// 42 DOCS INTRO

/* typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 1919, 1079, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
} */

// free  style

/* int main()
{
	void *mlx;
	void *win;
	void	*img;
	char	*relative_path = "./insta.xpm";
	int		img_width;
	int		img_height;

	img_height = 800;
	img_width = 800;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "Tutorial Window");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
} */

// 42 tutorial

/* void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
} */