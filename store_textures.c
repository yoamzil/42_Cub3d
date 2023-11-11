/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:39:49 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/11 15:30:01 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	store_north(t_game *game, char **map, int i)
{
	int	j;
	int	k;
	
	j = 3;
	k = 0;
	game->NO = malloc(ft_strlen(map[i]) - 4);
	while ((size_t)j < ft_strlen(map[i]))
	{
		game->NO[k] = map[i][j];
		k++;
		j++;
	}
}

void	store_south(t_game *game, char **map, int i)
{
	int	j;
	int	k;
	
	j = 3;
	k = 0;
	game->SO = malloc(ft_strlen(map[i]) - 4);
	while ((size_t)j < ft_strlen(map[i]))
	{
		game->SO[k] = map[i][j];
		k++;
		j++;
	}
}

void	store_west(t_game *game, char **map, int i)
{
	int	j;
	int	k;
	
	j = 3;
	k = 0;
	game->WE = malloc(ft_strlen(map[i]) - 4);
	while ((size_t)j < ft_strlen(map[i]))
	{
		game->WE[k] = map[i][j];
		k++;
		j++;
	}
}

void	store_east(t_game *game, char **map, int i)
{
	int	j;
	int	k;
	
	j = 3;
	k = 0;
	game->EA = malloc(ft_strlen(map[i]) - 4);
	while ((size_t)j < ft_strlen(map[i]))
	{
		game->EA[k] = map[i][j];
		k++;
		j++;
	}
}

void	store_textures(t_game *game, char **map)
{
	int	i;
	
	i = 0;
	while (i < 6)
	{
		if (map[i][0] == 'N')
			store_north(game, map, i);
		if (map[i][0] == 'S')
			store_south(game, map, i);
		if (map[i][0] == 'W')
			store_west(game, map, i);
		if (map[i][0] == 'E')
			store_east(game, map, i);
		if (map[i][0] == 'F')
			store_floor(game, map, i);
		if (map[i][0] == 'C')
			store_ceiling(game, map, i);
		i++;
	}
}
