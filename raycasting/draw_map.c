/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:55:33 by omakran           #+#    #+#             */
/*   Updated: 2023/11/16 12:57:48 by omakran          ###   ########.fr       */
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
			mlx_put_pixel(game->mini_map, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_square_player(t_game *game, int x, int y, int __unused color)
{
	int	i;
	int	j;

	i = x;
	while (i < x + 20)
	{
		j = y;
		while (j < y + 20)
		{
			mlx_put_pixel(game->mini_map, j, i, color);
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
			i++;
		}
		j++;
	}
	drawing_the_player(game);
}
