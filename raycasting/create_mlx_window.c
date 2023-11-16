/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:53:47 by omakran           #+#    #+#             */
/*   Updated: 2023/11/16 12:06:01 by omakran          ###   ########.fr       */
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
	return (EXIT_SUCCESS);
}

void	start(t_game *game)
{
	intialize_window(game);
	get_player_position(game);
	mlx_loop_hook(game->win, ft_hook, game);
	mlx_loop(game->win);
	mlx_terminate(game->win);
}
