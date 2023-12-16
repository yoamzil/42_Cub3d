/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:03 by omakran           #+#    #+#             */
/*   Updated: 2023/12/16 16:46:35 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	is_within_window(int x, int y)
{
	return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

int	check_if_hit_wall(t_game *game, double x, double y)
{
	float	new_x;
	float	new_y;

	if (x <= 0 || x >= SQUAR_SIZE * game->width
		|| y <= 0 || y >= SQUAR_SIZE * game->height)
		return (1);
	new_x = floor(x / SQUAR_SIZE);
	new_y = floor(y / SQUAR_SIZE);
	if (new_x <= 0 || new_x >= game->width
		|| new_y < 0 || new_y >= game->height)
		return (1);
	if (game->map[(int)new_y][(int)new_x] == '1')
		return (1);
	return (0); 
}

t_game	*get_wall_height(t_game *game)
{
	game->player_pos->wall_height = (SQUAR_SIZE
			/ game->player_pos->distance) * ((WIDTH / 2) / tan(M_PI / 4));
	game->player_pos->ystart = (HEIGHT / 2)
		- (game->player_pos->wall_height / 2);
	game->player_pos->yend = (HEIGHT / 2) + (game->player_pos->wall_height / 2);
	return (game);
}

t_game	*the_closest_point(t_game *game)
{
	if (game->player_pos->dist_vert > game->player_pos->dist_hori)
	{
		game->player_pos->x_step = game->hori->x_hori;
		game->player_pos->y_step = game->hori->y_hori;
		game->player_pos->distance = game->player_pos->dist_hori;
		game->hori->is_hori = 1;
		game->ver->is_ver = 0;
	}
	else 
	{
		game->player_pos->x_step = game->ver->x_ver;
		game->player_pos->y_step = game->ver->y_ver;
		game->player_pos->distance = game->player_pos->dist_vert;
		game->hori->is_hori = 0;
		game->ver->is_ver = 1;
	}
	return (game);
}
