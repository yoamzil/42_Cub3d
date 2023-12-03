/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:21:01 by omakran           #+#    #+#             */
/*   Updated: 2023/12/03 16:34:07 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
int abs(int n) { return ((n > 0) ? n : (n * (-1))); } 
uint32_t color(int r, int g, int b, int a){
	return (r << 24 | g << 16 | b << 8 | a);
}

void DDA(t_game *map, int X0, int Y0, int X1, int Y1) 
{ 
    float dx = X1 - X0; 
    float dy = Y1 - Y0; 
    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 
    float Xinc = (dx / (float)steps); 
    float Yinc = (dy / (float)steps) ;

    float X = X0; 
    float Y = Y0; 
	
    for (int i = 0; i <= steps; i++) 
	{
			if ((round(X) >= 0 && round(X) < WIDTH) && (round(Y) >= 0 && round(Y) < HEIGHT) && !check_if_hit_wall(map, X, Y))
	        	// mlx_put_pixel(map->mini_map,round(X), round(Y), color(255,0,0,255)); // put pixel at (X,Y) 
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
    }
}

void	drawing_the_player(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (j < game->height)
	{
		i = 0;
		while (i < game->width && game->map[j][i])
		{
			if (game->map[j][i] == 'N' || game->map[j][i] == 'S'
				|| game->map[j][i] == 'E' || game->map[j][i] == 'W')
			{
				draw_square_player(game, game->player_pos->y,
					game->player_pos->x, ft_pixel(0, 255, 0, 255));
				break ;
			}
			i++;
		}
		j++;
	}
	game->rayangle = game->player_pos->rotation_angle - to_radian(FOV / 2);
}

float	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	ft_rotate_player(t_game *game)
{
	game->player_pos->rotation_angle = \
		normalize_angle(game->player_pos->rotation_angle);
	if (mlx_is_key_down(game->win, MLX_KEY_LEFT))
		game->player_pos->rotation_angle -= ((float)1 / 10);
	else if (mlx_is_key_down(game->win, MLX_KEY_RIGHT))
		game->player_pos->rotation_angle += ((float)1 / 10);
	else
		return ;
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->win, MLX_KEY_ESCAPE))
		mlx_close_window(game->win);
	if (mlx_is_key_down(game->win, MLX_KEY_W))
		movement(game, MLX_KEY_W);
	if (mlx_is_key_down(game->win, MLX_KEY_S))
		movement(game, MLX_KEY_S);
	if (mlx_is_key_down(game->win, MLX_KEY_D))
		movement(game, MLX_KEY_D);
	if (mlx_is_key_down(game->win, MLX_KEY_A))
		movement(game, MLX_KEY_A);
	else
		ft_rotate_player(game);
	erase_drawing(game);
	drawing_ciel_and_floor(game);
	raycast(game);
	draw_map(game);
	drawing_the_player(game);
}
