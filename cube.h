/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:09 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/21 13:11:50 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

# define TILE_SIZE 30
# define WIDTH 1800
# define HEIGHT 1600
# define SQUAR_SIZE 50
# define SQUAR_SIZE_PLAYER 5
# define PLAYER_MOVE 1
# define PI 3.14159265
// # define FOV_ANGLE (60 * (PI / 180))

/* ################## My Structs: ########################*/

typedef struct s_player_x_y
{
	float	x;	
	float	y;	
	float	rotation_angle;
	int		direction;
	float	radians;
}	t_player_x_y;

typedef struct s_game
{
	char			**map;
	char			direction;
	int				width;
	int				height;
	int				start_position;
	mlx_t			*win;
	mlx_image_t		*img;
	mlx_image_t		*mini_map;
	char			**file;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	int				no_count;
	int				so_count;
	int				we_count;
	int				ea_count;
	int				f_count;
	int				c_count;
	t_player_x_y	*player_pos;
}				t_game;

/* ########################################################*/

/* ################## Helpers Functions:  #########################*/

int				is_valid_map(t_game *game, int i);
int				is_valid_arg(char *arg);
int				is_surrounded_by_walls(char **map, int i);
int				is_valid_map_chars(char **map, int i);
int				has_valid_pec(t_game *game, int i);
int				has_double_newline(char *map);
int				has_right_identifiers(t_game game, char **map);
int				has_right_rgb(t_game game);
int				tab_counter(char **tab);
int				free_tab(char **tab);
int				check_numbers(char *str);
int				comma_count(char *str);
int				intialize_window(t_game *game);
int				close_game(void *param);
int				ft_pixel(int r, int g, int b, int a);
void			ft_hook(void *param);
void			drawing(t_game *game);
void			store_textures(t_game *game, char **map);
void			store_floor(t_game *game, char **map, int i);
void			store_ceiling(t_game *game, char **map, int i);
void			error(void);
void			start(t_game *game);
void			draw_square(t_game *game, int x, int y, int __unused color);
void			draw_square_player(t_game *game, int x, int y, \
								int __unused color);
void			erase_drawing(t_game *game);
void			init_variables(t_game *game);
void			draw_map(t_game *game);
void			drawing_the_player(t_game *game);
void			get_player_position(t_game *game);
void			set_direction(t_game *game);
float			to_radian(float nb);
char			direction_of_player(t_game *game);

/* #####################################################################*/

/* ################## Function Of  Moves: ###############*/

void			can_move_to_up(t_game *game);
void			can_move_to_down(t_game *game);
void			can_move_to_right(t_game *game);
void			can_move_to_left(t_game *game);

/* ######################################################*/
#endif