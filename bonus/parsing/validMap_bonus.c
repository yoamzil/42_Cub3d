/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validMap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:41 by yoamzil           #+#    #+#             */
/*   Updated: 2023/12/17 13:46:41 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

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

int	walls_support(char **map, int height)
{
	int	i;
	int	j;

	j = 5;
	while (++j < height)
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0' || map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'E' || map[j][i] == 'W')
			{
				if ((i > 0 && map[j][i - 1] == ' ') || (i == 0)
					|| (map[j][i + 1] && map[j][i + 1] == ' ')
					|| (j > 0 && map[j - 1][i] == ' ') || (j == 6)
					|| (map[j + 1] && map[j + 1][i] == ' ') || !map[j + 1]
					|| !map[j][i + 1]
					|| (map[j + 1] && ft_strlen(map[j + 1]) < (size_t)i + 1)
					|| (j > 0 && ft_strlen(map[j - 1]) < (size_t)i + 1))
					return (0);
			}
		}
	}
	return (1);
}

int	is_surrounded_by_walls(char **map, int i)
{
	int	height;
	int	width;

	height = i;
	while (map[height])
		height++;
	width = ft_strlen(map[i]);
	if (width < 2 || height < 2)
		return (0);
	if (walls_support(map, height))
		return (1);
	return (0);
}

int	is_valid_map_chars(char **map, int i)
{
	int		j;
	char	c;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != 'N' && c != 'S' && c != 'E'
				&& c != 'W' && c != '0' && c != '1' && c != ' ')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	has_valid_pec(t_game *game, int i)
{
	int	j;

	j = 0;
	game->start_position = 0;
	while (game->file[++i])
	{
		j = 0;
		while (game->file[i][j])
		{
			if (game->file[i][j] == 'N')
				game->start_position++;
			if (game->file[i][j] == 'S')
				game->start_position++;
			if (game->file[i][j] == 'E')
				game->start_position++;
			if (game->file[i][j] == 'W')
				game->start_position++;
			j++;
		}
	}
	if (game->start_position != 1)
		return (0);
	return (1);
}
