/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:03 by omakran           #+#    #+#             */
/*   Updated: 2023/11/18 19:34:40 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	can_move_to_up(t_game *game)
{
	double	x;
	double	y;

	x = game->player_pos->x;
	y = game->player_pos->y - SQUAR_SIZE_PLAYER;
	if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
	{
		if (game->map[((int)y) / SQUAR_SIZE][((int)x) / SQUAR_SIZE] != '1')
		{
			game->player_pos->x = x;
			game->player_pos->y = y; 
		}
	}
}

void	can_move_to_down(t_game *game)
{
	double	x;
	double	y;

	x = game->player_pos->x;
	y = game->player_pos->y + SQUAR_SIZE_PLAYER;
	if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
	{
		if (game->map[((int)y) / SQUAR_SIZE][((int)x) / SQUAR_SIZE] != '1')
		{
			game->player_pos->x = x;
			game->player_pos->y = y; 
		}
	}
}

void	can_move_to_right(t_game *game)
{
	double	x;
	double	y;

	x = game->player_pos->x + SQUAR_SIZE_PLAYER;
	y = game->player_pos->y;
	if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
	{
		if (game->map[((int)y) / SQUAR_SIZE][((int)x) / SQUAR_SIZE] != '1')
		{
			game->player_pos->x = x;
			game->player_pos->y = y; 
		}
	}
}

void	can_move_to_left(t_game *game)
{
	double	x;
	double	y;

	x = game->player_pos->x - SQUAR_SIZE_PLAYER;
	y = game->player_pos->y;
	if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
	{
		if (game->map[((int)y) / SQUAR_SIZE][((int)x) / SQUAR_SIZE] != '1')
		{
			game->player_pos->x = x;
			game->player_pos->y = y; 
		}
	}
}
