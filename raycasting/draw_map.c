/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:55:33 by omakran           #+#    #+#             */
/*   Updated: 2023/11/26 17:58:49 by omakran          ###   ########.fr       */
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

void	draw_line(t_game *game)
{
	float	rotation_angle;
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	int		color;
	float	dx;
	float	dy;
	int		steps;
	float	x_inc;
	float	y_inc;
	float	X;
	float	Y;

	rotation_angle = game->player_pos->rotation_angle;
	x0 = game->player_pos->x;
	y0 = game->player_pos->y;
	x1 =	x0 + (100) * cos(rotation_angle);
	y1 = y0 + (100) * sin(rotation_angle);
	color = 255;
	dx = x1 -	x0;
	dy = y1 - y0;
	steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	X =	x0;
	Y = y0;
	for (int i = 0; i <= steps; i++)
	{
		mlx_put_pixel(game->mini_map, X, Y, color);
		if (game->mini_map == NULL)
			break ;
		X += x_inc;
		Y += y_inc;
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
			if (game->map[j][i] == 'N'
				|| (game->map[j][i] == 'S') | (game->map[j][i] == 'E')
				|| (game->map[j][i] == 'W'))
			{
				draw_square(game, j * 50, i * 50, ft_pixel(255, 255, 255, 255));
			}
			i++;
		}
		j++;
	}
}
