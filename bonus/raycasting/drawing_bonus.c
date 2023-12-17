/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:45 by omakran           #+#    #+#             */
/*   Updated: 2023/12/17 14:12:39 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h" 

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
				mlx_put_pixel(game->mini_map, j, i, ft_pixel(0, 0, 0, 0));
			else
				mlx_put_pixel(game->mini_map, j, i, ft_pixel(0, 0, 10, 255));
			j++;
		}
		i++;
	}
}

void	draw_it_helper(t_game *game, t_drawit *drawit, int id)
{
	drawit->pixelx = &game->texture[game->sides]
		->pixels[(((int)drawit->yoffset 
				* game->texture[game->sides]->width)
			+ (int)drawit->xoffset)
		* game->texture[game->sides]->bytes_per_pixel];
	drawit->pixeli = &game->mini_map
		->pixels[(((int)drawit->start_tmp_y
				* game->mini_map->width)
			+ id) * game->texture[game->sides]->bytes_per_pixel];
	if (game->player_pos->ystart < HEIGHT)
		ft_memmove(drawit->pixeli, drawit->pixelx,
			game->texture[game->sides]->bytes_per_pixel);
}

void	draw_it(t_game *game, int id)
{
	t_drawit	*drawit;

	drawit = malloc(sizeof(t_drawit));
	drawit->start_tmp_y = ((HEIGHT / 2) - (game->player_pos->wall_height) / 2);
	drawit->xoffset = (game->texture[game->sides]->width / SQUAR_SIZE
			* (game->touch - (int)(game->touch / SQUAR_SIZE) * SQUAR_SIZE));
	while (game->player_pos->ystart < game->player_pos->yend)
	{
		drawit->wall_height = game->player_pos->wall_height;
		drawit->offsety = (HEIGHT - drawit->wall_height) / 2;
		drawit->yoffset = (game->player_pos->ystart - drawit->offsety)
			* ((float)game->texture[game->sides]->height / drawit->wall_height);
		if (game->player_pos->ystart >= 0 && game->player_pos->ystart <= HEIGHT)
		{
			draw_it_helper(game, drawit, id);
		}
		game->player_pos->ystart++;
		drawit->start_tmp_y++; 
	}
}

void	drawing(t_game *game)
{
	draw_map(game);
}
