/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:00:09 by omakran           #+#    #+#             */
/*   Updated: 2023/12/16 15:59:30 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	is_there_a_wall(t_game *game, float x, float y)
{
	int	x_move;
	int	y_move;

	x_move = x + 1;
	y_move = y + 1;
	x_move = floor(x_move / SQUAR_SIZE);
	y_move = floor(y_move / SQUAR_SIZE);
	if (x < 0 || x > game->width * SQUAR_SIZE
		|| y < 0 || y > game->height * SQUAR_SIZE)
		return (0);
	if (game->map[(int)(game->player_pos->y
			/ SQUAR_SIZE)][(int)(x / SQUAR_SIZE)] == '1')
		return (0);
	if (game->map[(int)(y
			/ SQUAR_SIZE)][(int)(game->player_pos->x / SQUAR_SIZE)] == '1')
		return (0);
	if (x_move <= 0 || x_move >= game->width * SQUAR_SIZE
		|| y_move <= 0 || y_move >= game->height * SQUAR_SIZE)
		return (0);
	if (game->map[y_move][x_move] == '1')
		return (0);
	return (1);
}

void	can_move_a_w(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = 0;
	new_y = 0;
	if (mlx_is_key_down(game->win, MLX_KEY_A))
	{
		new_x = game->player_pos->x + game->player_pos->move_speed
			* cos(game->player_pos->rotation_angle - (M_PI / 2));
		new_y = game->player_pos->y + game->player_pos->move_speed
			* sin(game->player_pos->rotation_angle - (M_PI / 2));
	}
	else if (mlx_is_key_down(game->win, MLX_KEY_W))
	{
		new_x = game->player_pos->x + game->player_pos->move_speed
			* cos(game->player_pos->rotation_angle);
		new_y = game->player_pos->y + game->player_pos->move_speed
			* sin(game->player_pos->rotation_angle);
	}
	if (is_there_a_wall(game, new_x, new_y) == 1)
	{
		game->player_pos->x = new_x;
		game->player_pos->y = new_y;
	}
}

void	can_move_s_d(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = 0;
	new_y = 0;
	if (mlx_is_key_down(game->win, MLX_KEY_S))
	{
		new_x = game->player_pos->x - game->player_pos->move_speed
			* cos(game->player_pos->rotation_angle);
		new_y = game->player_pos->y - game->player_pos->move_speed
			* sin(game->player_pos->rotation_angle);
	}
	else if (mlx_is_key_down(game->win, MLX_KEY_D))
	{
		new_x = game->player_pos->x + game->player_pos->move_speed
			* cos(game->player_pos->rotation_angle + M_PI / 2);
		new_y = game->player_pos->y + game->player_pos->move_speed
			* sin(game->player_pos->rotation_angle + M_PI / 2);
	}
	if (is_there_a_wall(game, new_x, new_y) == 1)
	{
		game->player_pos->x = new_x;
		game->player_pos->y = new_y;
	}
}
