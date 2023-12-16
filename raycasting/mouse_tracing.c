/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_tracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:19:33 by omakran           #+#    #+#             */
/*   Updated: 2023/12/16 23:41:18 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    mouse_tracer(void *param)
{
    t_game *game;
    int     y;
    int     x;

    game = (t_game *)param;
    mlx_get_mouse_pos(game->win, &x, &y);
    if (x < game->mouse->x)
    {
        game->mouse->x = x;
        game->mouse->y = y;
        game->player_pos->rotation_angle -= ((float)1 / 25);
    }
    if (x > game->mouse->x)
    {
        game->mouse->x = x;
        game->mouse->y = y;
        game->player_pos->rotation_angle += ((float)1 / 25);
    }
    // drawing_ciel_and_floor(game);
	// raycast(game);
}