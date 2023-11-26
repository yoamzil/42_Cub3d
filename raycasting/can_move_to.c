/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:00:09 by omakran           #+#    #+#             */
/*   Updated: 2023/11/26 16:07:02 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	can_move_to_up(t_game *game, int key)
{
	if (key == MLX_KEY_W)
	{
		game->player_pos->new_x = game->player_pos->x + game->player_pos->dx;
		game->player_pos->new_y = game->player_pos->y + game->player_pos->dy;
	}
}

void	can_move_to_down(t_game *game, int key)
{
	if (key == MLX_KEY_S)
	{
		game->player_pos->new_x = game->player_pos->x - game->player_pos->dx;
		game->player_pos->new_y = game->player_pos->y - game->player_pos->dy;
	}
}

void	can_move_to_right(t_game *game, int key)
{
	if (key == MLX_KEY_D)
	{
		game->player_pos->new_x = game->player_pos->x - game->player_pos->dy;
		game->player_pos->new_y = game->player_pos->y + game->player_pos->dx;
	}
}

void	can_move_to_left(t_game *game, int key)
{
	if (key == MLX_KEY_A)
	{
		game->player_pos->new_x = game->player_pos->x + game->player_pos->dy;
		game->player_pos->new_y = game->player_pos->y - game->player_pos->dx;
	}
}
