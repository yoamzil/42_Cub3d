/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:21:01 by omakran           #+#    #+#             */
/*   Updated: 2023/11/16 11:59:41 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	get_player_position(t_game *game)
{
	int	i;
	int	j;

	game->player_pos = malloc(sizeof(t_player_x_y));
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
			{
				game->player_pos->x = j * SQUAR_SIZE;
				game->player_pos->y = i * SQUAR_SIZE;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->img = malloc(sizeof(mlx_image_t));
	if (mlx_is_key_down(game->win, MLX_KEY_ESCAPE))
		mlx_close_window(game->win);
	if (mlx_is_key_down(game->win, MLX_KEY_UP))
		game->player_pos->y -= 1;
	if (mlx_is_key_down(game->win, MLX_KEY_DOWN))
		game->player_pos->y += 1;
	if (mlx_is_key_down(game->win, MLX_KEY_LEFT))
		game->player_pos->x -= 1;
	if (mlx_is_key_down(game->win, MLX_KEY_RIGHT))
		game->player_pos->x += 1;
	draw_map(game);
}
