/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:09 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/09 16:28:33 by yoamzil          ###   ########.fr       */
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
	char	**textures;
	int		start_position_count;
}	t_game;

int	is_valid_map(t_game *game);
int	is_valid_arg(char *arg);
int	is_surrounded_by_walls(char **map);
int	is_valid_map_chars(char **map);
int	has_valid_pec(t_game *game);
int	has_double_newline(char *map);

#endif