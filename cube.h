/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:09 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/14 19:32:24 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

#ifndef BPP 
# define BPP sizeof(int)
#endif

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		start_position;
	char	**file;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		no_count;
	int		so_count;
	int		we_count;
	int		ea_count;
	int		f_count;
	int		c_count;
}	t_game;

int		is_valid_map(t_game *game, int i);
int		is_valid_arg(char *arg);
int		is_surrounded_by_walls(char **map, int i);
int		is_valid_map_chars(char **map, int i);
int		has_valid_pec(t_game *game, int i);
int		has_double_newline(char *map);
int		has_right_identifiers(t_game game, char **map);
void	store_textures(t_game *game, char **map);
void	store_floor(t_game *game, char **map, int i);
void	store_ceiling(t_game *game, char **map, int i);
int		has_right_rgb(t_game game);
int		tab_counter(char **tab);
int		free_tab(char **tab);
void	error(void);
int		check_numbers(char *str);
int		comma_count(char *str);
int		intialize_window(void);
int		close_game(void *param);
void	draw_square(void *win, int x, int y, int size_square, int color);
void	init_variables(t_game *game);

#endif