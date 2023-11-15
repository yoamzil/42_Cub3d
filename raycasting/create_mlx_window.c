/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:53:47 by omakran           #+#    #+#             */
/*   Updated: 2023/11/15 15:46:44 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

// void ft_randomize()
// {
// 	unsigned int	i;
// 	unsigned int	y;
// 	int				color;

// 	i = 0;
// 	while (i < img->width)
// 	{
// 		y = 0;
// 		while (y < img->height)
// 		{
// 			color = ft_pixel(0xFF , 0xFF , 0xFF, 0xFF);
// 			mlx_put_pixel(img, i, y, color);
// 			y++;
// 		}
// 		i++;
// 	}
// }

void	ft_hook(void *param)
{
	t_game	*game;
	mlx_t	*mlx;

	game = (t_game *)param;
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		game->img->instances[0].y -= 7;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		game->img->instances[0].y += 7;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		game->img->instances[0].x -= 7;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		game->img->instances[0].x += 7;
}

int	intialize_window(t_game *game)
{
	game->win = mlx_init(game->width * 50, game->height * 50, "cub3D", true);
	if (!game->win)
	{
		ft_putstr_fd("Error Initializing MLX!.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini_map = mlx_new_image(game->win, \
		game->width * 50, game->height * 50);
	if (!(game->mini_map))
	{
		ft_putstr_fd("Error Initializing MINI_MAP.\n", 2);
		exit(EXIT_FAILURE);
	}
	drawing(game);
	if (mlx_image_to_window(game->win, game->mini_map, 0, 0) == -1)
	{
		mlx_close_window(game->win);
		ft_putstr_fd("Error Initializing WIN.\n", 2);
		exit(EXIT_FAILURE);
	}
	mlx_loop(game->win);
	mlx_terminate(game->win);
	return (EXIT_SUCCESS);
}

void	start(t_game *game)
{
	intialize_window(game);
	mlx_loop_hook(game->win, ft_hook, game->win);
}
