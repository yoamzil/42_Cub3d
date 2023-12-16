/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:43:19 by omakran           #+#    #+#             */
/*   Updated: 2023/12/16 18:51:20 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_the_vertical(t_game *game, float *ray_angle)
{
	while (1)
	{
		if ((game->player_pos->is_facing_left
				&& check_if_hit_wall(game, game->ver->x_ver
					- SQUAR_SIZE, game->ver->y_ver))
			|| (!game->player_pos->is_facing_left
				&& (check_if_hit_wall(game, game->ver->x_ver,
						game->ver->y_ver)))
			|| (game->player_pos->is_facing_left
				&& check_if_hit_wall(game, game->ver->x_ver, game->ver->y_ver)))
			break ;
		game->ver->x_ver += game->player_pos->sign * SQUAR_SIZE;
		game->ver->y_ver += game->player_pos->sign
			* SQUAR_SIZE * tan(*ray_angle);
	}
}

void	vertical_steps(t_game *game, float ray_angle)
{
	game->player_pos->sign = 1;
	game->ver->x_ver = 0;
	game->ver->y_ver = 0;
	ray_angle = normalize_angle(ray_angle);
	game->player_pos->is_facing_left = ray_angle > M_PI
		/ 2 && ray_angle < 1.5 * M_PI;
	game->ver->x_ver = ceil(game->player_pos->x / SQUAR_SIZE) * SQUAR_SIZE;
	if (game->player_pos->is_facing_left)
	{
		game->cast->is_ray_facing_left = 1;
		game->ver->x_ver -= SQUAR_SIZE;
		game->player_pos->sign = -1;
	}
	if (!game->player_pos->is_facing_left)
		game->cast->is_ray_facing_left = 0;
	game->ver->y_ver = game->player_pos->y
		- (game->player_pos->x - game->ver->x_ver) * tan(ray_angle);
	check_the_vertical(game, &ray_angle);
}
