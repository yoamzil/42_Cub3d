/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:45 by omakran           #+#    #+#             */
/*   Updated: 2023/11/22 17:29:50 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	erase_drawing(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
				mlx_put_pixel(game->mini_map, x, y, ft_pixel(0, 0, 0, 255));
			x++;
		}
		y++;
	}
}

void	drawing(t_game *game)
{
	draw_map(game);
}
