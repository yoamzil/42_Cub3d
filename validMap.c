/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:41 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/08 22:09:46 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_valid_arg(char *arg)
{
	int	len;

	if (!arg)
		return (0);
	len = 0;
	while (arg[len] != '\0')
		len++;
	if (arg[len - 1] == 'b' && arg[len - 2] == 'u'
		&& arg[len - 3] == 'c' && arg[len - 4] == '.')
	{
		return (1);
	}
	return (0);
}

int	is_surrounded_by_walls(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	if (width < 2 || height < 2)
		return (0);
	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
		{
			if (map[j][i] == '0')
			{
				if ((i > 0 && map[j][i - 1] == ' ') || (i == 0) || (i < width - 1 && map[j][i + 1] == ' ') || (j > 0 && map[j - 1][i] == ' ') || (j == 0) || (j < height - 1 && map[j + 1][i] == ' '))
					return (0);
			}
		}
	}
	return (1);
}

int	is_valid_map_chars(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != 'N' && c != 'S' && c != 'E' 
				&& c != 'W' && c != '0' && c != '1')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	has_valid_pec(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	game->start_position_count = 0;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
				game->start_position_count++;
			else if (game->map[i][j] == 'S')
				game->start_position_count++;
			else if (game->map[i][j] == 'E')
				game->start_position_count++;
			else if (game->map[i][j] == 'W')
				game->start_position_count++;
			j++;
		}
	}
	if (game->start_position_count != 1)
		return (0);
	return (1);
}

int	is_valid_map(t_game *game)
{
	if (is_surrounded_by_walls(game->map))
		return (1);
	return (0);
}
