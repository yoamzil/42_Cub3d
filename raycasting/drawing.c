/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:45 by omakran           #+#    #+#             */
/*   Updated: 2023/12/16 21:56:52 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h" 

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

void	draw_it(t_game *game, float  x_tx, mlx_texture_t  *texture, int  id)
{
	(void)x_tx;
	(void)texture;
	float	 start_tmp_y;
	float  xoffset;
	float  yoffset;
	uint8_t* pixeli;
	uint8_t* pixelx;

	start_tmp_y = ((HEIGHT / 2) - (game->player_pos->wall_height) / 2);
	xoffset = (game->texture[game->sides]->width / SQUAR_SIZE * (game->touch - (int)(game->touch / SQUAR_SIZE) * SQUAR_SIZE));
	while (game->player_pos->ystart < game->player_pos->yend)
	{
		float wall_height = game->player_pos->wall_height;
		int offsety = (HEIGHT - wall_height) / 2;
		yoffset = (game->player_pos->ystart - offsety) * ((float)game->texture[game->sides]->height / wall_height);
		if(game->player_pos->ystart >= 0 && game->player_pos->ystart <= HEIGHT)
		{
			pixelx = &game->texture[game->sides]->pixels[(((int)yoffset * game->texture[game->sides]->width)
					+ (int)xoffset) * game->texture[game->sides]->bytes_per_pixel];
			pixeli = &game->mini_map->pixels[(((int)start_tmp_y * game->mini_map->width)
					+ id) * game->texture[game->sides]->bytes_per_pixel];
			if (game->player_pos->ystart < HEIGHT)
				ft_memmove(pixeli, pixelx, game->texture[game->sides]->bytes_per_pixel);
		}
		game->player_pos->ystart++;
		start_tmp_y++; 
	}
}

void	drawing(t_game *game)
{
	draw_map(game);
}
