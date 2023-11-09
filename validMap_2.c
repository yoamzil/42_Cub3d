/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validMap_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:03 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/09 16:22:34 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_valid_map(t_game *game)
{
	if (is_surrounded_by_walls(game->map)
		&& is_valid_map_chars(game->map) && has_valid_pec(game))
		return (1);
	return (0);
}

int	has_double_newline(char *map)
{
	while (*map)
	{
		if (*map == '\n' && *(map + 1) == '\n')
		{
			printf("Error\nEmpty Line Found\n");
			exit(1);
		}
		map++;
	}
	return (0);
}
