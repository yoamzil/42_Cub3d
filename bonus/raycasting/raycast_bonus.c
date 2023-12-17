/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:55:37 by omakran           #+#    #+#             */
/*   Updated: 2023/12/17 13:47:33 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

t_game	*valid_distance(t_game *game, float ray_angle)
{
	float	angle;

	angle = normalize_angle(ray_angle);
	horizontal_steps(game, ray_angle);
	vertical_steps(game, ray_angle);
	game->player_pos->dist_vert = get_distance(game->player_pos->x,
			game->player_pos->y, game->ver->x_ver, game->ver->y_ver);
	game->player_pos->dist_hori = get_distance(game->player_pos->x,
			game->player_pos->y, game->hori->x_hori, game->hori->y_hori);
	game = the_closest_point(game);
	game->player_pos->distance = game->player_pos->distance
		* cos(ray_angle - game->player_pos->rotation_angle);
	return (game);
}

void	calculate_touch_and_x_tx(t_game *game)
{
	if (game->ver->is_ver == 1)
	{
		game->touch = game->ver->y_ver;
		game->x_tx = (int)game->player_pos->y_step % SQUAR_SIZE;
	}
	else
	{
		game->touch = game->hori->x_hori;
		game->x_tx = (int)game->player_pos->x_step % SQUAR_SIZE;
	}
}

void	determine_sides_and_draw(t_game *game, int id)
{
	if (game->player_pos->dist_vert > game->player_pos->dist_hori)
	{
		if (sin(game->rayangle) > 0)
			game->sides = 1;
		else
			game->sides = 0;
		if (game->cast->is_ray_facing_up == 1)
			draw_it(game, id);
		else
			draw_it(game, id);
	}
	else
	{
		if (cos(game->rayangle) > 0)
			game->sides = 3;
		else
			game->sides = 2;
		if (game->cast->is_ray_facing_left == 1)
			draw_it(game, id);
		else
			draw_it(game, id);
	}
}

void	casting_the_rays(t_game *game, float ray_angle, int __unused id)
{
	game = valid_distance(game, ray_angle);
	game = get_wall_height(game);
	calculate_touch_and_x_tx(game);
	determine_sides_and_draw(game, id);
}

void	raycast(t_game *game)
{
	int	rays;

	rays = 0;
	game->rayangle = normalize_angle(game->player_pos->rotation_angle
			- (game->player_pos->fov_angle / 2));
	while (rays < WIDTH)
	{
		casting_the_rays(game, game->rayangle, rays);
		game->rayangle += normalize_angle(game->player_pos->fov_angle / WIDTH);
		rays++;
	}
}
