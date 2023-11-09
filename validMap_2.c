/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validMap_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:03 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/09 21:45:52 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_valid_map(t_game *game, int i)
{
	if (is_surrounded_by_walls(game->map, i)
		&& is_valid_map_chars(game->map, i) && has_valid_pec(game, i))
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
