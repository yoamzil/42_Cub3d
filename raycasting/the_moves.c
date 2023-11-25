/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:03 by omakran           #+#    #+#             */
/*   Updated: 2023/11/25 21:01:31 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int is_within_window(int x, int y)
{
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

int collides_with_wall(t_game *game, int x, int y)
{
    int map_x = x / SQUAR_SIZE;
    int map_y = y / SQUAR_SIZE;

    return game->map[map_y][map_x] == '1';
}

void    movement(t_game *game, int key)
{
    int    dx;
    int    dy;
    int     new_x;
    int     new_y;

    dx = SQUAR_SIZE_PLAYER * cos(game->player_pos->rotation_angle);
    dy = SQUAR_SIZE_PLAYER * sin(game->player_pos->rotation_angle);
    if (key == MLX_KEY_W)
    {
        new_x = game->player_pos->x + dx;
        new_y = game->player_pos->y + dy;
    }
    if (key == MLX_KEY_S)
    {
        new_x = game->player_pos->x - dx;
        new_y = game->player_pos->y - dy;
    }
    if (key == MLX_KEY_D)
    {
        new_x = game->player_pos->x - dy;
        new_y = game->player_pos->y + dx;
    }
    if (key == MLX_KEY_A)
    {
		new_x = game->player_pos->x + dy;
		new_y = game->player_pos->y - dx;
	}
    if (!collides_with_wall(game, new_x + SQUAR_SIZE_PLAYER / 2, new_y + SQUAR_SIZE_PLAYER / 2) && is_within_window(new_x + SQUAR_SIZE_PLAYER / 2, new_y + SQUAR_SIZE_PLAYER / 2))
    {
        game->player_pos->x = new_x;
        game->player_pos->y = new_y;
    }
}
