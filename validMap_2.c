/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validMap_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:03 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/12 11:51:36 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_valid_map(t_game *game, int i)
{
	if (is_surrounded_by_walls(game->map, i)
		&& is_valid_map_chars(game->map, i) && has_valid_pec(game, i)
		&& has_right_identifiers(*game, game->map))
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
		if (map[i] == '1' && map[i + 1] == '1' && map[i + 3] != ',')
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

int	has_right_identifiers(t_game game, char **map)
{
	int	i;

	i = 0;
	while (map[i] && i < 6)
	{
		if (!ft_strncmp("NO ", map[i], 3) && game.NO_count == 0)
            game.NO_count = 1;
		if (!ft_strncmp("SO ", map[i], 3) && game.SO_count == 0)
            game.SO_count = 1;
		if (!ft_strncmp("WE ", map[i], 3) && game.WE_count == 0)
            game.WE_count = 1;
		if (!ft_strncmp("EA ", map[i], 3) && game.EA_count == 0)
            game.EA_count = 1;
		if (!ft_strncmp("F ", map[i], 2) && game.F_count == 0)
            game.F_count = 1;
		if (!ft_strncmp("C ", map[i], 2) && game.C_count == 0)
            game.C_count = 1;
		if (game.NO_count + game.SO_count + game.WE_count + game.EA_count + game.F_count + game.C_count == 6)
			return (1);
		i++;
	}
	return (0);
}

void has_right_rgb(t_game game)
{
    char    **rgb_array;
    int     i;

    rgb_array = ft_split(game.F, ',');
    i = 0;
    while (rgb_array[i])
        i++;
    if (i == 3)
    {
        printf("howa hadak\n");
    }
    else 
        printf("mashy howa hadak\n");
}
