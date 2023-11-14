/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:53:47 by omakran           #+#    #+#             */
/*   Updated: 2023/11/14 13:35:36 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

#define WIDTH 512
#define HEIGHT 512
#define MAP_WIDTH 13
#define MAP_HEIGHT 11
#define TILE_SIZE 30

static mlx_image_t	*img;


void	draw_square(void __unused *img , int x, int y, int size_square, int __unused color)
{
	int	i;
	int	j;

	i = x;
	while (i < x + size_square)
	{
		j = y;
		while (j < y + size_square)
		{
			mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}

int ft_pixel(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize()
{
	unsigned int	i;
	unsigned int	y;
	int				color;

	i = 0;
	while (i < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			color = ft_pixel(0xFF , 0xFF , 0xFF, 0xFF);
			
			mlx_put_pixel(img, i, y, color);
			y++;
		}
		i++;
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 7;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 7;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 7;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 7;
}
int	intialize_window(void)
{
	mlx_t		*win;
	mlx_image_t *img;
	win = mlx_init(800, 600, "cub3D", true);

	// if (!win)
	// {
	// 	ft_putstr_fd("Error Initializing MLX!.\n", 2);
	// 	exit (EXIT_FAILURE);
	// }
	if (!(img = mlx_new_image(win,800, 600)))
	{
		ft_putstr_fd("Error Initializing IMG.\n", 2);
		exit (EXIT_FAILURE);
	}
	draw_square(img, 0, 0, 100, 0xFFFFF);
	if (mlx_image_to_window(win, img, 0, 0) == -1)
	{
		mlx_close_window(win);
		ft_putstr_fd("Error Initializing WIN.\n", 2);
		exit (EXIT_FAILURE);
	}
	// mlx_loop_hook(win, ft_randomize, win);
	// mlx_loop_hook(win, ft_hook, win);
	mlx_loop(win);
	mlx_terminate(win);
	return (EXIT_SUCCESS);
}
