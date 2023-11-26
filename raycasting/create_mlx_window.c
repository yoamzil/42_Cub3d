/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:53:47 by omakran           #+#    #+#             */
/*   Updated: 2023/11/26 18:48:15 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	intialize_window(t_game *game)
{
	game->win = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game->win)
	{
		ft_putstr_fd("Error Initializing MLX!.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini_map = mlx_new_image(game->win, WIDTH, HEIGHT);
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
	set_up(game);
	drawing_the_player(game);
	mlx_loop_hook(game->win, ft_hook, game);
	mlx_loop(game->win);
	mlx_terminate(game->win);
}
