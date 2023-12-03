/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:21:01 by omakran           #+#    #+#             */
/*   Updated: 2023/12/03 17:42:32 by omakran          ###   ########.fr       */
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
	if (mlx_is_key_down(game->win, MLX_KEY_W))
		movement(game, MLX_KEY_W);
	if (mlx_is_key_down(game->win, MLX_KEY_S))
		movement(game, MLX_KEY_S);
	if (mlx_is_key_down(game->win, MLX_KEY_D))
		movement(game, MLX_KEY_D);
	if (mlx_is_key_down(game->win, MLX_KEY_A))
		movement(game, MLX_KEY_A);
	else
		ft_rotate_player(game);
	drawing_ciel_and_floor(game);
	raycast(game);
}
