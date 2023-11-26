/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:21:01 by omakran           #+#    #+#             */
/*   Updated: 2023/11/26 19:58:56 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
int abs(int n) { return ((n > 0) ? n : (n * (-1))); } 
uint32_t color(int r, int g, int b, int a){
	return (r << 24 | g << 16 | b << 8 | a);
}
// DDA Function for line generation 
void DDA(t_game *map, int X0, int Y0, int X1, int Y1) 
{ 
    // calculate dx & dy 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float)steps; 
    float Yinc = dy / (float)steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) { 
        mlx_put_pixel(map->mini_map,round(X), round(Y), color(255,0,0,255)); // put pixel at (X,Y) 
        X += Xinc; // increment in x at each step 
        Y += Yinc; // increment in y at each step 
    } 
}
void	drawing_the_player(t_game *game)
{
	int	i;
	int	j;

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
	int z = 0;
	game->rayangle = game->player_pos->rotation_angle - to_radian(FOV / 2);
	float x;
	float y;
	while (z < WIDTH){
	// 	puts("hana");
		x= cos(game->rayangle ) * 50;
		y= sin(game->rayangle ) * 50 ;
		DDA(game, game->player_pos->x, game->player_pos->y,  x + game->player_pos->x , y+game->player_pos->y);
		game->rayangle += to_radian(FOV) / WIDTH;
		z++;
	}
	
}

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= (2 * M_PI))
		angle -= 2 * M_PI;
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
	draw_map(game);
	drawing_the_player(game);
	// draw_line(game);
}
