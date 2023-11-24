/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:03 by omakran           #+#    #+#             */
/*   Updated: 2023/11/24 19:56:33 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    get_cord_to_move(t_game *game, int __unused *new_x, int __unused *new_y, int key)
{
    int    dx;
    int    dy;

    dx = SQUAR_SIZE_PLAYER * cos(game->player_pos->rotation_angle);
    dy = SQUAR_SIZE_PLAYER * sin(game->player_pos->rotation_angle);
    if (key == MLX_KEY_W)
    {
        game->player_pos->x = game->player_pos->x + dx;
        game->player_pos->y = game->player_pos->y + dy;
    }
    if (key == MLX_KEY_S)
    {
        game->player_pos->x = game->player_pos->x - dx;
        game->player_pos->y = game->player_pos->y - dy;
    }
    if (key == MLX_KEY_D)
    {
        game->player_pos->x = game->player_pos->x - dy;
        game->player_pos->y = game->player_pos->y + dx;
    }
    if (key == MLX_KEY_A)
    {
		game->player_pos->x = game->player_pos->x + dy;
		game->player_pos->y = game->player_pos->y - dx;
	}
}
