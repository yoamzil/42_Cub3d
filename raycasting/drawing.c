/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:45 by omakran           #+#    #+#             */
/*   Updated: 2023/12/11 21:56:29 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	get_texture(t_game *game)
{
	game->texture[0] = mlx_load_png(game->no);
	game->texture[1] = mlx_load_png(game->so);
	game->texture[2] = mlx_load_png(game->we);
	game->texture[3] = mlx_load_png(game->ea);
	if (!game->texture[0] || !game->texture[1] || !game->texture[2] || !game->texture[3])
		printf("invalid textures");
}

// void    init_points(t_int_coords *p1, t_int_coords *p2, t_two_coords *twin)
// {
//     p1->x = twin->tex.x;
//     p1->y = -1;
//     p2->x = twin->img.x;
//     p2->y = twin->img.y - 1;
// }

// void    draw_text(t_game *data, t_two_coords twin, float h, mlx_texture_t *tex)
// {
//     t_int_coords    p1;
//     t_int_coords    p2;
//     uint8_t            *px;
//     uint8_t            *pi;

//     init_points(&p1, &p2, &twin);
//     if (h > data->img->height)
//         p1.y = (h - data->img->height) / 2;
//     if (p2.y < 0)
//         p2.y = 0;
//     while (++p2.y < (int)data->img->height - 1 && ++p1.y < h - 1)
//     {
//         twin.tex.y = p1.y * ((float) tex->height / (float) h);
//         if (twin.tex.y < tex->height
//             && (twin.tex.y * tex->width + p1.x) < tex->width * tex->height)
//         {
//             px = &tex->pixels
//             [(((int)twin.tex.y * tex->width) + p1.x) * tex->bytes_per_pixel];
//             pi = &data->img->pixels
//             [((p2.y * (data->img->width)) + p2.x) * tex->bytes_per_pixel];
//             ft_memmove(pi, px, tex->bytes_per_pixel);
//         }
//     }
// }

// void    draw_columns(t_game *data, t_coords p, float height, t_ray ray)
// {
//     t_two_coords    twin;
//     mlx_texture_t    *texture;
//     float            width_ratio;

//     twin.img.x = p.x;
//     twin.img.y = p.y;
//     if (ray.is_horz)
//     {
//         texture = data->texture[0];
//         if (ray.is_facing_up)
//             texture = data->texture[1];
//         width_ratio = (float)((float)texture->width / (float) TILE_SIZE);
//         twin.tex.x = fmod(ray.x, TILE_SIZE) * (width_ratio);
//     }
//     else
//     {
//         texture = data->texture[2];
//         if (ray.is_facing_left)
//             texture = data->texture[3];
//         width_ratio = (float)((float)texture->width / (float)TILE_SIZE);
//         twin.tex.x = fmod(ray.y, TILE_SIZE) * (width_ratio);
//     }
//     draw_text(data, twin, height, texture);
// }

// void    draw_3d_wall(t_game *data, t_ray_cast *cast, float i)
// {
// 	t_ray ray;
//     t_coords    p;
	
// 	ray.x = cast->wall_hit_x;
// 	ray.y = cast->wall_hit_y;
// 	ray.distance = cast->distance;
// 	ray.is_horz = !cast->was_hit_vertical;
// 	ray.is_facing_up = cast->is_ray_facing_up;
// 	ray.is_facing_down = cast->is_ray_facing_down;
// 	ray.is_facing_left = cast->is_ray_facing_left;
// 	ray.is_facing_right = cast->is_ray_facing_right;

//     p.x = i;
//     p.y = ((HEIGHT / 2) - (((HEIGHT / 2) * 50) / ray.distance));
//     draw_columns(data, p, HEIGHT - (p.y * 2), ray);
// }

// // textures functions up there
int	ft_pixel_texture(int x, int y, mlx_texture_t *texture)
{
	int	i;

	i = ((y * 4) * texture->width) + (x * 4);
	// return (texture->pixels[i] << 24 | texture->pixels[i + 1] << 16 | texture->pixels[i + 2] << 8 | texture->pixels[i + 3]);
	return (0x0FAE2);
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
				mlx_put_pixel(game->mini_map, j, i, ft_pixel(0, 155, 155, 255));
			else
				mlx_put_pixel(game->mini_map, j, i, ft_pixel(0, 255, 0, 255));
			j++;
		}
		i++;
	}
}
int32_t	getcolor(mlx_texture_t *img, int y, int x)
{
	int	inc;

	if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
	{
		inc = (img->width * y + x) * img->bytes_per_pixel;
		return (ft_pixel(img->pixels[inc], img->pixels[inc + 1],
				img->pixels[inc + 2], 255));
	}
	return (ft_pixel(0, 0, 0, 0));
}

void	draw_it(t_game *game, float x_tx, mlx_texture_t *texture, int id)
{
	(void)id;
	float	top_the_wall_pixel;
	float	x_intercept;
	float	start_tmp_y;
	float	y_tx;
	float xoffset;
	float yoffset;
	uint32_t color;

	start_tmp_y = ((HEIGHT / 2) - (game->player_pos->wall_height) / 2);
	x_intercept = game->texture[game->sides]->height / (float)game->player_pos->wall_height;
	top_the_wall_pixel = start_tmp_y;
	float fact = game->texture[game->sides]->height / (float)game->player_pos->wall_height;
	while (game->player_pos->ystart < game->player_pos->yend)
	{
		float distop = game->player_pos->ystart + ((float)game->player_pos->wall_height/2) - (HEIGHT / 2);
		xoffset = (int)game->touch % game->texture[game->sides]->width;
		yoffset = distop * fact / 2;
		color = getcolor(game->texture[game->sides], yoffset, xoffset);
		y_tx = (game->player_pos->ystart - top_the_wall_pixel) * x_tx;
		if (y_tx >= texture->height)
			y_tx = 0;
		// draw_3d_wall(game, game->cast start_tmp_y);
		mlx_put_pixel(game->mini_map, id, game->player_pos->ystart, color);
		game->player_pos->ystart++;
		start_tmp_y++;
	}
}

void	drawing(t_game *game)
{
	draw_map(game);
}
