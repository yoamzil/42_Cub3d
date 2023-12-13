/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:55:37 by omakran           #+#    #+#             */
/*   Updated: 2023/12/11 21:51:29 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_if_hit_wall(t_game *game, double x, double y)
{
	float	new_x;
	float	new_y;

	if (x <= 0 || x >= SQUAR_SIZE * game->width
		|| y <= 0 || y >= SQUAR_SIZE * game->height)
		return (1);
	new_x = floor(x / SQUAR_SIZE);
	new_y = floor(y / SQUAR_SIZE);
	if (new_x <= 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
		return (1);
	if (game->map[(int)new_y][(int)new_x] == '1')
		return (1);
	return (0); 
}

t_game	*get_wall_height(t_game *game)
{
	game->player_pos->wall_height = (SQUAR_SIZE / game->player_pos->distance) * ((WIDTH / 2) / tan(M_PI / 4));
	game->player_pos->ystart = (HEIGHT / 2) - (game->player_pos->wall_height / 2);
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

float	get_distance(float x_1, float y_1, float x_2, float y_2)
{
	return (sqrt(((x_2 - x_1) * (x_2 - x_1)) + ((y_2 - y_1) * (y_2 - y_1))));
}

t_game	*valid_distance(t_game *game, float ray_angle)
{
	float	angle;

	angle = normalize_angle(ray_angle);
	horizontal_steps(game, ray_angle);
	vertical_steps(game, ray_angle);
	game->player_pos->dist_vert = get_distance(game->player_pos->x, game->player_pos->y, game->ver->x_ver, game->ver->y_ver);
	game->player_pos->dist_hori = get_distance(game->player_pos->x, game->player_pos->y, game->hori->x_hori, game->hori->y_hori);
	game = the_closest_point(game);
	game->player_pos->distance = game->player_pos->distance * cos(ray_angle - game->player_pos->rotation_angle);
	return (game);
}

void	casting_the_rays(t_game *game, float ray_angle, int id)
{
	game = valid_distance(game, ray_angle);
	game = get_wall_height(game);
	if (game->ver->is_ver == 1)
	{
		game->touch =  game->ver->y_ver;
		game->x_tx = (int)game->player_pos->y_step % SQUAR_SIZE;
	}
	else
	{
		game->touch =  game->hori->x_hori;
		game->x_tx = (int)game->player_pos->x_step % SQUAR_SIZE;
	}
	if (game->player_pos->dist_vert > game->player_pos->dist_hori)
	{
		if (sin(game->rayangle) > 0)
			game->sides = 1;
		else
			game->sides = 0;
		if (game->cast->is_ray_facing_up == 1)
			draw_it(game, game->x_tx, game->textrs->no_t, id);
		else
			draw_it(game, game->x_tx, game->textrs->so_t, id);
	}
	else
	{
		if (cos(game->rayangle) > 0)
			game->sides = 3;
		else
			game->sides = 2;
		if (game->cast->is_ray_facing_left == 1)
			draw_it(game, game->x_tx, game->textrs->we_t, id);
		else
			draw_it(game, game->x_tx, game->textrs->ea_t, id);
	}
}

void	raycast(t_game *game)
{
	int	rays;

	rays = 0;
	game->rayangle = normalize_angle(game->player_pos->rotation_angle - (game->player_pos->fov_angle / 2));
	while (rays < WIDTH)
	{
		casting_the_rays(game, game->rayangle, rays);
		game->rayangle += normalize_angle(game->player_pos->fov_angle / WIDTH);
		rays++;
	}
}
