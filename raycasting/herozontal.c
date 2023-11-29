/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herozontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:43:22 by omakran           #+#    #+#             */
/*   Updated: 2023/11/29 18:31:05 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	horizontal_steps(t_game *game)
{
	game->hori = malloc(sizeof(t_hori));
	game->hori->y_intercept = floor(game->player_pos->y / SQUAR_SIZE) * SQUAR_SIZE;
	game->hori->x_intercept = game->player_pos->x  + (game->hori->y_intercept - game->player_pos->y) / tan(game->rayangle);
	if (sin(game->rayangle) > 0)
		game->hori->y_intercept += SQUAR_SIZE;
	if (cos(game->rayangle) < 0)
		game->hori->x_intercept = game->player_pos->x - fabs(game->hori->x_intercept);
	else
		game->hori->x_intercept = game->player_pos->x + fabs(game->hori->x_intercept);
	game->hori->y_step = SQUAR_SIZE;
	if (sin(game->rayangle) < 0)
		game->hori->y_step *= -1;
	game->hori->x_step = SQUAR_SIZE / tan(game->rayangle);
	if ((cos(game->rayangle) < 0 && game->hori->x_step > 0) || (cos(game->rayangle) > 0 && game->hori->x_step < 0))
		game->hori->x_step *= -1;
	game->hori->x_hori = game->hori->x_intercept;
	game->hori->y_hori = game->hori->y_intercept;
	// if (sin(game->rayangle) < 0)
	// 	game->hori->y_hori -= 0.001;
}
