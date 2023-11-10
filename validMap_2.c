/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validMap_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:03 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/10 18:57:28 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_valid_map(t_game *game, int i)
{
	if (is_surrounded_by_walls(game->map, i)
		&& is_valid_map_chars(game->map, i) && has_valid_pec(game, i) && has_right_identifiers(game->map))
		return (1);
	return (0);
}

int	has_double_newline(char *map)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '1' && map[i + 1] == '1'
			&& map[i + 2] == '1' && map[i + 3] == '1')
			count = 1;
		if (count == 1 && map[i] == '\n' && map[i + 1] == '\n')
		{
			printf("Error\nEmpty Line Found\n");
			exit(1);
		}
		i++;
	}
	return (0);
}

int	has_right_identifiers(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i] && i < 6)
	{
		if (!ft_strncmp("NO ", map[i], 2) || !ft_strncmp("SO ", map[i], 2) || !ft_strncmp("WE ", map[i], 2) || !ft_strncmp("EA ", map[i], 2))
		{
			count++;
		}
		if (count == 4)
			return (1);
		i++;
	}
	return (0);
}
