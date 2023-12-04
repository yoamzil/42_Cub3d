/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:03 by omakran           #+#    #+#             */
/*   Updated: 2023/12/04 09:56:51 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	is_within_window(int x, int y)
{
	return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

int	collides_with_wall(t_game *game, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = x / SQUAR_SIZE;
	map_y = y / SQUAR_SIZE;
	return (game->map[map_y][map_x] == '1');
}

void	movement(t_game *game, int key)
{
	game->player_pos->dx = SQUAR_SIZE_PLAYER
		* cos(game->player_pos->rotation_angle);
	game->player_pos->dy = SQUAR_SIZE_PLAYER
		* sin(game->player_pos->rotation_angle);
	if (key == MLX_KEY_W)
		can_move_to_up(game, MLX_KEY_W);
	if (key == MLX_KEY_S)
		can_move_to_down(game, MLX_KEY_S);
	if (key == MLX_KEY_D)
		can_move_to_right(game, MLX_KEY_D);
	if (key == MLX_KEY_A)
		can_move_to_left(game, MLX_KEY_A);
	if (!collides_with_wall(game, game->player_pos->new_x, game->player_pos->new_y)
		&& is_within_window(game->player_pos->new_x + (SQUAR_SIZE_PLAYER / 2),
			game->player_pos->new_y + (SQUAR_SIZE_PLAYER / 2)))
	{
		game->player_pos->x = game->player_pos->new_x;
		game->player_pos->y = game->player_pos->new_y;
	}
}
