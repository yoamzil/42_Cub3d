/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:45 by omakran           #+#    #+#             */
/*   Updated: 2023/12/16 18:52:09 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_pixel_texture(int x, int y, mlx_texture_t *texture)
{
	int	i;

	i = ((y * 4) * texture->width) + (x * 4);
	return (0x0FAE2);
}

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
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
				mlx_put_pixel(game->mini_map, j, i, ft_pixel(0, 155, 155, 255));
			else
				mlx_put_pixel(game->mini_map, j, i, ft_pixel(0, 255, 0, 255));
			j++;
		}
		i++;
	}
}

void	draw_it(t_game *game, float x_tx, mlx_texture_t *texture, int id)
{
	t_drawit	*drawit;
	float		distop;

	drawit = malloc(sizeof(t_drawit));
	drawit->start_tmp_y = ((HEIGHT / 2) - (game->player_pos->wall_height) / 2);
	drawit->x_intercept = game->texture[game->sides]->height
		/ (float)game->player_pos->wall_height;
	drawit->top_the_wall_pixel = drawit->start_tmp_y;
	drawit->xoffset = ((int)game->touch % TILE_SIZE)
		* game->texture[game->sides]->width / TILE_SIZE;
	while (game->player_pos->ystart < game->player_pos->yend)
	{
		distop = game->player_pos->ystart
			+ ((float)game->player_pos->wall_height / 2) - (HEIGHT / 2);
		drawit->yoffset = distop * drawit->x_intercept;
		drawit->y_tx = (game->player_pos->ystart - drawit->top_the_wall_pixel)
			* x_tx;
		if (drawit->y_tx >= texture->height)
			drawit->y_tx = 0;
		if (game->player_pos->ystart >= 0 && game->player_pos->ystart <= HEIGHT)
		{
			drawit->pixelx = &game->texture[game->sides]
				->pixels[(((int)drawit->yoffset
						* game->texture[game->sides]->width)
					+ (int)drawit->xoffset)
				* game->texture[game->sides]->bytes_per_pixel];
			drawit->pixeli = &game->mini_map
				->pixels[(((int)drawit->start_tmp_y * game->mini_map->width)
					+ id) * game->texture[game->sides]->bytes_per_pixel];
			if (game->player_pos->ystart < HEIGHT)
				ft_memmove(drawit->pixeli, drawit->pixelx,
					game->texture[game->sides]->bytes_per_pixel);
		}
		game->player_pos->ystart++;
		drawit->start_tmp_y++;
	}
	drawit->y_tx = texture->height;
}

void	drawing(t_game *game)
{
	draw_map(game);
}
