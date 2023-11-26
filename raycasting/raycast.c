/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:55:37 by omakran           #+#    #+#             */
/*   Updated: 2023/11/26 19:56:52 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

// void	raycast(t_game *game)
// {
// 	int column;
// 	int i;
// 	float ray_angle;

// 	column = 0;
// 	ray_angle = game->player_pos->rotation_angle - (game->player_pos->fov_angle
// 			/ 2);
// 	i = 0;
// 	while (i < game->player_pos->num_rays)
// 	{
// 		draw_line(game->mini_map, game->player_pos->x, game->player_pos->y,
// 			game->player_pos->x + cos(game->player_pos->rotation_angle) * 30,
// 			game->player_pos->y + sin(game->player_pos->rotation_angle) * 30,
// 			255);
// 		i++;
// 	}
// }