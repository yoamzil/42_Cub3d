/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:55:37 by omakran           #+#    #+#             */
/*   Updated: 2023/11/29 19:08:36 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

// double calculate_distance(double x1, double y1, double x2, double y2)
// {
//     return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
// }

// typedef struct
// {
// 	float x;
// 	float y;
// } t_vec;

// void get_short_dist(float *x, float *y, t_game *game)
// {
// 	double hor[2];
// 	double ver[2];
// 	get_horizontal(game, hor);
// 	get_vertical(game, ver);
// 	double i = calculate_distance(game->player_pos->x, game->player_pos->y, hor[0], hor[1]);
// 	double j = calculate_distance(game->player_pos->x, game->player_pos->y, ver[0], ver[1]);
// 	if (i < j)
// 	{
// 		*x = hor[0];
// 		*y = hor[1];
// 	}
// 	else
// 	{
// 		*x = ver[0];
// 		*y = ver[1];
// 	}
// }

int check_if_hit_wall(t_game *game, double x, double y)
{
	float	new_x;
	float	new_y;

	if (x <= 0 || x >= SQUAR_SIZE * WIDTH || y <= 0 || y >= SQUAR_SIZE * HEIGHT)
		return (0);
	new_x = floor(x / SQUAR_SIZE);
	new_y = floor(y / SQUAR_SIZE);
	if (new_x <= 0 || new_x >= WIDTH || new_y < 0 || new_y >= HEIGHT)
		return (0);
	if (game->map[(int)new_y][(int)new_x] == '1')
		return (0);
	return (1); 
}

void get_horizontal(t_game *game, double *wall)
{
	horizontal_steps(game);
	while (true)
	{
		if (game->hori->x_hori >= (SQUAR_SIZE * WIDTH) || game->hori->x_hori < 0 || game->hori->y_hori >= (SQUAR_SIZE * HEIGHT) || (game->hori->y_hori < 0))
		{
			wall[0] = -1;
			wall[1] = -1;
			break;
		}
		if (check_if_hit_wall(game, game->hori->x_hori, game->hori->y_hori))
		{
			wall[0] = game->hori->x_hori;
			wall[1] = game->hori->y_hori;
			break;
		}
		game->hori->x_hori += game->hori->x_step;
		game->hori->y_hori += game->hori->y_step;
	}
}

void get_vertical(t_game *game, double *wall)
{
	vertical_steps(game);
	while (true)
	{
		if (game->ver->x_ver >= (SQUAR_SIZE * WIDTH) || game->ver->x_ver < 0 || game->ver->y_ver >= (SQUAR_SIZE * HEIGHT) || game->ver->y_ver < 0)
		{
			wall[0] = -1;
			wall[1] = -1;
			break;
		}
		if (check_if_hit_wall(game, game->ver->x_ver, game->ver->y_ver))
		{
			wall[0] = game->ver->x_ver;
			wall[1] = game->ver->y_ver;
			break;
		}
		game->ver->x_ver += game->ver->x_step;
		game->ver->y_ver += game->ver->y_step;
	}
}

