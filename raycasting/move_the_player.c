/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:21:01 by omakran           #+#    #+#             */
/*   Updated: 2023/11/26 17:19:20 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	drawing_the_player(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->height)
	{
		i = 0;
		while (i < game->width && game->map[j][i])
		{
			if (game->map[j][i] == 'N' || game->map[j][i] == 'S'
				|| game->map[j][i] == 'E' || game->map[j][i] == 'W')
			{
				draw_square_player(game, game->player_pos->y,
					game->player_pos->x, ft_pixel(0, 255, 0, 255));
				break ;
			}
			i++;
		}
		j++;
	}
}

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= (2 * M_PI))
		angle -= 2 * M_PI;
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
	erase_drawing(game);
	draw_map(game);
	drawing_the_player(game);
}
