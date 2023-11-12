/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:09 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/11 22:59:28 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

typedef struct s_game
{
	char	**map;
	char	*NO;
	char    *SO;
	char    *WE;
	char    *EA;
	char    *F;
	char    *C;
	int     NO_count;
	int     SO_count;
	int     WE_count;
	int     EA_count;
	int     F_count;
	int     C_count;
	int		start_position;
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
void    has_right_rgb(t_game game);

#endif