/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:55:33 by omakran           #+#    #+#             */
/*   Updated: 2023/11/24 18:12:36 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	draw_square(t_game *game, int x, int y, int __unused color)
{
	int	i;
	int	j;

	i = x;
	while (i < x + SQUAR_SIZE)
	{
		j = y;
		while (j < y + SQUAR_SIZE)
		{
			if ((j > 0 && j < WIDTH) && (i > 0 && i < HEIGHT))
			{
				mlx_put_pixel(game->mini_map, j, i, color);
			}
			j++;
		}
		i++;
	}
}

void draw_line(t_game *game)
{
    // Extract line parameters from the t_game structure
	float rotation_angle = game->player_pos->rotation_angle;
    float X0 = game->player_pos->x;
    float Y0 = game->player_pos->y;
    float X1 = X0 + (100) * cos(rotation_angle);
    float Y1 = Y0 + (100) * sin(rotation_angle);
    int color = 255;
    // calculate dx & dy
    float dx = X1 - X0;
    float dy = Y1 - Y0;
    // calculate steps required for generating pixels
    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

    // calculate increment in x & y for each step
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        // Assuming mlx_put_pixel is a function in your game structure
        mlx_put_pixel(game->mini_map, X, Y, color);
        if (game->mini_map == NULL)
            break; // put pixel at (X,Y)
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
    }
}

void	draw_square_player(t_game *game, int x, int y, int __unused color)
{
	int	i;
	int	j;

	i = x;
	while (i < x + SQUAR_SIZE_PLAYER)
	{
		j = y;
		while (j < y + SQUAR_SIZE_PLAYER)
		{
			if ((j > 0 && j < WIDTH) && (i > 0 && i < HEIGHT))
			{
				mlx_put_pixel(game->mini_map, j, i, color);
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->height)
	{
		i = 0;
		while (i < game->width && game->map[j][i])
		{
			if (game->map[j][i] == '1')
				draw_square(game, j * 50, i * 50, ft_pixel(0, 0, 0, 255));
			if (game->map[j][i] == '0')
				draw_square(game, j * 50, i * 50, ft_pixel(255, 255, 255, 255));
			if (game->map[j][i] == 'N' || (game->map[j][i] == 'S') 
				| (game->map[j][i] == 'E') || (game->map[j][i] == 'W'))
			{
				draw_square(game, j * 50, i * 50, ft_pixel(255, 255, 255, 255));
			}
			i++;
		}
		j++;
	}
}
