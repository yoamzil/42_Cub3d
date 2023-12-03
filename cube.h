/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:09 by yoamzil           #+#    #+#             */
/*   Updated: 2023/12/03 18:04:00 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include "MLX42/include/MLX42/MLX42.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

#define TILE_SIZE 50
#define WIDTH 1800
#define HEIGHT 1600
#define SQUAR_SIZE 50
#define SQUAR_SIZE_PLAYER 5
#define FALSE 0
#define TRUE 1
#define FOV 60

/*######################################################*/
/*                    My Structs:						*/
/*######################################################*/

typedef struct s_texters
{
	mlx_texture_t	*we_t;
	mlx_texture_t	*ea_t;
	mlx_texture_t	*no_t;
	mlx_texture_t	*so_t;
}			t_textrs;

typedef struct s_horizontal
{
	float x_hori;
	float y_hori;
	int is_hori;
} t_hori;

typedef struct s_vertical
{
	float x_ver;
	float y_ver;
	int is_ver;
} t_ver;

typedef struct s_player_x_y
{
	float x;
	float y;
	int new_x;
	int new_y;
	int dx;
	int dy;
	int	sign;
	float rotation_angle;
	float radians;
	float fov_angle;
	float wall_strip_width;
	float dist_hori;
	float dist_vert;
	float distance;
	int wall_height;
	float num_rays;
	bool	is_facing_up;
	bool	is_facing_left;
	float x_step;
	float y_step;
	int direction;
	int ystart;
	int yend;

} t_player_x_y;

typedef struct s_ray_cast
{
	float ray_angle;
	float wall_hit_x;
	float wall_hit_y;
	float distance;
	bool was_hit_vertical;
	bool is_ray_facing_up;
	bool is_ray_facing_down;
	bool is_ray_facing_left;
	bool is_ray_facing_right;
	int wall_hit_content;
} t_ray_cast;

typedef	enum e_direction
{
	WE,
	EA,
	NO,
	SO,
}	t_direction;

typedef struct s_game
{
	char **map;
	t_direction direction;
	int width;
	int height;
	int start_position;
	mlx_t *win;
	mlx_image_t *img;
	mlx_image_t *mini_map;
	char **file;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *f;
	char *c;
	float rayangle;
	int no_count;
	int so_count;
	int we_count;
	int ea_count;
	int f_count;
	int c_count;
	float x_tx;
	t_player_x_y *player_pos;
	t_hori *hori;
	t_ray_cast	*cast;
	t_ver *ver;
	t_textrs *textrs;
} t_game;

/* ################################################################*/
/*						Helpers Functions:					       */
/* ################################################################*/

int is_valid_map(t_game *game, int i);
int is_valid_arg(char *arg);
int is_surrounded_by_walls(char **map, int i);
int is_valid_map_chars(char **map, int i);
int has_valid_pec(t_game *game, int i);
int has_double_newline(char *map);
int has_right_identifiers(t_game game, char **map);
int has_right_rgb(t_game *game);
int tab_counter(char **tab);
int free_tab(char **tab);
int check_numbers(char *str);
int comma_count(char *str);
int intialize_window(t_game *game);
int close_game(void *param);
int ft_pixel(int r, int g, int b, int a);
void ft_hook(void *param);
void drawing(t_game *game);
void store_textures(t_game *game, char **map);
void store_floor(t_game *game, char **map, int i);
void store_ceiling(t_game *game, char **map, int i);
void error(void);
void start(t_game *game);
void draw_square(t_game *game, int x, int y, int __unused color);
void erase_drawing(t_game *game);
void init_variables(t_game *game);
void draw_map(t_game *game);
void get_player_position(t_game *game);
void	drawing_ciel_and_floor(t_game *game);
void set_up(t_game *game);
float to_radian(float nb);
void	direction_of_player(t_game *game);

/* #####################################################################*/
/*						Function Of  Moves:								*/
/* #####################################################################*/

void movement(t_game *game, int key);
void can_move_to_up(t_game *game, int key);
void can_move_to_down(t_game *game, int key);
void can_move_to_right(t_game *game, int key);
void can_move_to_left(t_game *game, int key);

/* ##################################################################*/
/*					     Raycasting:								 */
/* ##################################################################*/

void	raycast(t_game *game);
float	normalize_angle(float angle);
void	horizontal_steps(t_game *game, float ray_angle);
void	vertical_steps(t_game *game, float ray_angle);
int		check_if_hit_wall(t_game *game, double x, double y);
t_game	*get_wall_height(t_game *game);
t_game	*the_closest_point(t_game *game);
t_game	*valid_distance(t_game *game, float ray_angle);
float	get_distance(float x_1, float y_1, float x_2, float y_2);
void	draw_it(t_game *game, float x_tx , mlx_texture_t *texture, int id);

/* ##################################################################*/
/*					     FREE THE DATA:								 */
/* ##################################################################*/

void	free_the_all_data(t_game *game);

#endif