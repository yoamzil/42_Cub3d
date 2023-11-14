/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validMap_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:03 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/14 16:37:44 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
	while (map[i] && map[i + 3])
	{
		if (map[i] == '1' && map[i + 1] == '1' && map[i + 3] != ',')
			count = 1;
		if (count == 1 && map[i] == '\n' && map[i + 1] == '\n')
			error();
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
		if (!ft_strncmp("NO ", map[i], 3) && game.no_count == 0)
			game.no_count = 1;
		if (!ft_strncmp("SO ", map[i], 3) && game.so_count == 0)
			game.so_count = 1;
		if (!ft_strncmp("WE ", map[i], 3) && game.we_count == 0)
			game.we_count = 1;
		if (!ft_strncmp("EA ", map[i], 3) && game.ea_count == 0)
			game.ea_count = 1;
		if (!ft_strncmp("F ", map[i], 2) && game.f_count == 0)
			game.f_count = 1;
		if (!ft_strncmp("C ", map[i], 2) && game.c_count == 0)
			game.c_count = 1;
		if (game.no_count + game.so_count + game.we_count
			+ game.ea_count + game.f_count + game.c_count == 6)
			return (1);
		i++;
	}
	return (0);
}

int	has_right_rgb(t_game game)
{
	char	**rgb_f_array;
	char	**rgb_c_array;

	if (comma_count(game.f) != 2 || comma_count(game.c) != 2
		|| !check_numbers(game.f) || !check_numbers(game.c))
		error();
	rgb_f_array = ft_split(game.f, ',');
	rgb_c_array = ft_split(game.c, ',');
	if (tab_counter(rgb_f_array) == 3 && tab_counter(rgb_c_array) == 3)
	{
		if (ft_atoi(rgb_f_array[0]) >= 0 && ft_atoi(rgb_f_array[0]) <= 255
			&& ft_atoi(rgb_f_array[1]) >= 0 && ft_atoi(rgb_f_array[1]) <= 255
			&& ft_atoi(rgb_f_array[2]) >= 0 && ft_atoi(rgb_f_array[2]) <= 255
			&& ft_atoi(rgb_c_array[0]) >= 0 && ft_atoi(rgb_c_array[0]) <= 255
			&& ft_atoi(rgb_c_array[1]) >= 0 && ft_atoi(rgb_c_array[1]) <= 255
			&& ft_atoi(rgb_c_array[2]) >= 0 && ft_atoi(rgb_c_array[2]) <= 255)
			return (0);
		else 
			error();
	}
	else
		error();
	return (1);
}
