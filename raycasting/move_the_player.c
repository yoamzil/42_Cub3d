/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:21:01 by omakran           #+#    #+#             */
/*   Updated: 2023/11/18 19:43:26 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	get_player_position(t_game *game)
{
	int	i;
	int	j;

	game->player_pos = malloc(sizeof(t_player_x_y));
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
					game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->player_pos->x = j * SQUAR_SIZE + (SQUAR_SIZE / 2);
				game->player_pos->y = i * SQUAR_SIZE + (SQUAR_SIZE / 2);
				break ;
			}
			j++;
		}
		i++;
	}
}

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
			if (game->map[j][i] == 'N' || game->map[j][i] == 'S' ||
					game->map[j][i] == 'E' || game->map[j][i] == 'W')
			{
				draw_square(game, j * 20, i * 20, ft_pixel(255, 255, 255, 255));
				draw_square_player(game, game->player_pos->y,
					game->player_pos->x, ft_pixel(0, 255, 0, 255));
				break ;
			}
			i++;
		}
		j++;
	}
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->win, MLX_KEY_ESCAPE))
		mlx_close_window(game->win);
	else if (mlx_is_key_down(game->win, MLX_KEY_W))
		can_move_to_up(game);
	else if (mlx_is_key_down(game->win, MLX_KEY_S))
		can_move_to_down(game);
	else if (mlx_is_key_down(game->win, MLX_KEY_A))
		can_move_to_left(game);
	else if (mlx_is_key_down(game->win, MLX_KEY_D))
		can_move_to_right(game);
	eares_drawing(game);
	draw_map(game);
	drawing_the_player(game);
}
// else
// 	game->player_pos->x -= 1;
