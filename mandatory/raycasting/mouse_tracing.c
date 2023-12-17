/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_tracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:19:33 by omakran           #+#    #+#             */
/*   Updated: 2023/12/17 13:12:11 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	mouse_tracer(void *param)
{
	int		y;
	int		x;
	t_game	*game;

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
}
