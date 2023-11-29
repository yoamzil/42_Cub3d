/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:43:19 by omakran           #+#    #+#             */
/*   Updated: 2023/11/29 17:20:16 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	vertical_steps(t_game *game)
{
	game->ver = malloc(sizeof(t_ver));
	game->ver->x_intercept = floor(game->player_pos->x / SQUAR_SIZE) * SQUAR_SIZE;
	game->ver->y_intercept = (game->player_pos->x - game->ver->x_intercept) * tan(game->rayangle);
	if (cos(game->rayangle) > 0)
		game->ver->x_intercept += SQUAR_SIZE;
	if (sin(game->rayangle) > 0)
		game->ver->y_intercept = game->player_pos->y + fabs(game->ver->y_intercept);
	else
		game->ver->y_intercept = game->player_pos->y - fabs(game->ver->y_intercept);
	game->ver->x_step = SQUAR_SIZE;
	if (cos(game->rayangle) < 0)
		game->ver->y_step *= -1;
	game->ver->y_step = SQUAR_SIZE * tan(game->rayangle);
	if ((sin(game->rayangle) > 0 && game->ver->y_step < 0) || (sin(game->rayangle) < 0 && game->ver->y_step > 0))
		game->ver->y_step *= -1;
	game->ver->x_ver = game->ver->x_intercept;
	game->ver->x_ver = game->ver->y_intercept;
	// if (cos(game->rayangle) < 0)
	// 	game->ver->x_ver -= 0.001;
}