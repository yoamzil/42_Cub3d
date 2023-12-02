/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herozontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:43:22 by omakran           #+#    #+#             */
/*   Updated: 2023/12/02 22:14:53 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_the_horizontal(t_game *game, float *ray_angle)
{
	while (1)
	{
		if ((game->player_pos->is_facing_up && check_if_hit_wall(game, game->hori->x_hori, game->hori->y_hori - SQUAR_SIZE)) 
			|| (!game->player_pos->is_facing_up && (check_if_hit_wall(game, game->hori->x_hori, game->hori->y_hori)))
				|| (game->player_pos->is_facing_up && check_if_hit_wall(game, game->hori->x_hori, game->hori->y_hori)))
			break ;
		game->hori->x_hori += game->player_pos->sign *  SQUAR_SIZE / tan(*ray_angle);
		game->hori->y_hori +=  game->player_pos->sign * SQUAR_SIZE;
	}
}
void	horizontal_steps(t_game *game, float ray_angle)
{
	game->player_pos->sign = 1;
	game->hori->y_hori = 0;
	game->player_pos->is_facing_up = ray_angle > M_PI && ray_angle < 2 * M_PI;
	if (game->player_pos->is_facing_up)
	{
		game->cast->is_ray_facing_up = 1;
		game->player_pos->sign = -1;
	}
	game->hori->y_hori = floor(game->player_pos->y / SQUAR_SIZE) * SQUAR_SIZE;
	if (!game->player_pos->is_facing_up)
	{
		game->hori->y_hori += SQUAR_SIZE;
		game->cast->is_ray_facing_up = 0;
	}
	game->hori->x_hori = game->player_pos->x + (game->hori->y_hori - game->player_pos->y) / tan(ray_angle);
	check_the_horizontal(game, &ray_angle);
}
