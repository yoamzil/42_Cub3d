/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:21:01 by omakran           #+#    #+#             */
/*   Updated: 2023/12/06 22:13:51 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

float	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	ft_rotate_player(t_game *game)
{
	game->player_pos->rotation_angle = \
		normalize_angle(game->player_pos->rotation_angle);
	if (mlx_is_key_down(game->win, MLX_KEY_LEFT))
		game->player_pos->rotation_angle -= ((float)1 / 10);
	else if (mlx_is_key_down(game->win, MLX_KEY_RIGHT))
		game->player_pos->rotation_angle += ((float)1 / 10);
	else
		return ;
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->win, MLX_KEY_ESCAPE))
		mlx_close_window(game->win);
	if (mlx_is_key_down(game->win, MLX_KEY_W) || mlx_is_key_down(game->win, MLX_KEY_A))
		can_move_a_w(game);
	if (mlx_is_key_down(game->win, MLX_KEY_S) || mlx_is_key_down(game->win, MLX_KEY_D))
		can_move_s_d(game);
	else
		ft_rotate_player(game);
	drawing_ciel_and_floor(game);
	raycast(game);
	// draw_map(game);
	// drawing_the_player(game);
}
