/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:45 by omakran           #+#    #+#             */
/*   Updated: 2023/12/02 20:40:39 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_pixel_texture(int x, int y, mlx_texture_t *texture)
{
	int	i;
	i = ((y * 4) * texture->width) + (x * 4);
	// return (texture->pixels[i] << 24 | texture->pixels[i + 1] << 16 | texture->pixels[i + 2] << 8 | texture->pixels[i + 3]);
	return 0x0FAE2;
}
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

void	drawing_ciel_and_floor(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < (HEIGHT))
	{
		j = 0;
		while (j < (WIDTH))
		{
			if (i < (HEIGHT) / 2)
				mlx_put_pixel(game->mini_map, j, i, ft_pixel(0, 255, 0, 255));
			else
				mlx_put_pixel(game->mini_map, j, i, ft_pixel(0, 155, 155, 255));
			j++;
		}
		i++;
	}
}
void	draw_it(t_game *game, float x_tx , mlx_texture_t *texture, int id)
{
	float	top_the_wall_pixel;
	float	x_intercept;
	float	start_tmp_y;
	float	y_tx;
	
	
	start_tmp_y = ((HEIGHT / 2) - (game->player_pos->wall_height) / 2);
	x_intercept = texture->height / (float)game->player_pos->wall_height;
	top_the_wall_pixel = start_tmp_y;
	while (game->player_pos->ystart < game->player_pos->yend)
	{
		y_tx = (game->player_pos->ystart - top_the_wall_pixel) * x_tx;
		if (y_tx >= texture->height)
			y_tx = 0;
		mlx_put_pixel(game->mini_map, id, game->player_pos->ystart, ft_pixel_texture(x_tx, y_tx, texture));
		game->player_pos->ystart++;
		start_tmp_y++;
	}
}
void	drawing(t_game *game)
{
	draw_map(game);
}
