/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:58:00 by omakran           #+#    #+#             */
/*   Updated: 2023/12/17 13:47:18 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

int	close_game(void *param)
{
	param = NULL;
	exit(0);
	return (0);
}

int	check_if_hit_wall(t_game *game, float x, float y)
{
	float	new_x;
	float	new_y;

	if (x < 0 || x > SQUAR_SIZE * game->width
		|| y < 0 || y > game->height * SQUAR_SIZE)
		return (1);
	new_x = floor(x / SQUAR_SIZE);
	new_y = floor(y / SQUAR_SIZE);
	if (new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height \
	|| new_x >= ft_strlen(game->map[(int)new_y]))
		return (0);
	if (game->map[(int)new_y][(int)new_x] == '1')
		return (1);
	return (0);
}

t_game	*get_wall_height(t_game *game)
{
	game->player_pos->wall_height = (SQUAR_SIZE / game->player_pos->distance)
		* ((WIDTH / 2) / tan(game->player_pos->fov_angle / 2));
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
