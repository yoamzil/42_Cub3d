/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:21:01 by omakran           #+#    #+#             */
/*   Updated: 2023/11/18 16:25:13 by omakran          ###   ########.fr       */
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
				game->player_pos->x = j * SQUAR_SIZE;
				game->player_pos->y = i * SQUAR_SIZE;
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

int can_move_to_up(t_game *game)
{
    int x = game->player_pos->x / SQUAR_SIZE;
    int y = game->player_pos->y / SQUAR_SIZE - PLAYER_MOVE;

    if (y >= 0 && y < HEIGHT / SQUAR_SIZE && x >= 0 && x < WIDTH / SQUAR_SIZE)
	{
        if (game->map[y][x] == '1') 
            return (0); 
        return (1);
    }
    return (0);
}

int can_move_to_down(t_game *game)
{
    int x = game->player_pos->x / SQUAR_SIZE;
    int y = game->player_pos->y / SQUAR_SIZE + PLAYER_MOVE;

    if (y >= 0 && y < HEIGHT / SQUAR_SIZE && x >= 0 && x < WIDTH / SQUAR_SIZE)
	{
        if (game->map[y][x] == '1') 
            return (0);
        return (1);
    }
    return (0);
}

int can_move_to_right(t_game *game)
{
    int x = game->player_pos->x / SQUAR_SIZE + PLAYER_MOVE;
    int y = game->player_pos->y / SQUAR_SIZE;

    if (y >= 0 && y < HEIGHT / SQUAR_SIZE && x >= 0 && x < WIDTH / SQUAR_SIZE)
	{
        if (game->map[y][x] == '1') 
            return (0); 
        return (1);
    }
    return (0);
}

int can_move_to_left(t_game *game)
{
    int x = game->player_pos->x / SQUAR_SIZE - PLAYER_MOVE;
    int y = game->player_pos->y / SQUAR_SIZE;

    if (y >= 0 && y < HEIGHT / SQUAR_SIZE && x >= 0 && x < WIDTH / SQUAR_SIZE)
	{
        if (game->map[y][x] == '1')
            return (0);
        return (1);
    }
    return (0);
}

void ft_hook(void *param)
{
    t_game *game = (t_game *)param;

    if (mlx_is_key_down(game->win, MLX_KEY_ESCAPE))
        mlx_close_window(game->win);
    else if (mlx_is_key_down(game->win, MLX_KEY_W))
	{
        if (can_move_to_up(game) == 1)
            game->player_pos->y -= PLAYER_MOVE;
    }
    else if (mlx_is_key_down(game->win, MLX_KEY_S))
	{
        if (can_move_to_down(game) == 1)
            game->player_pos->y += PLAYER_MOVE;
    }
	else if (mlx_is_key_down(game->win, MLX_KEY_A))
	{
        if (can_move_to_left(game) == 1)
            game->player_pos->x -= PLAYER_MOVE;
    }
    else if (mlx_is_key_down(game->win, MLX_KEY_D))
	{
        if (can_move_to_right(game) == 1)
            game->player_pos->x += PLAYER_MOVE;
	}
	eares_drawing(game);
	draw_map(game);
	drawing_the_player(game);
}
