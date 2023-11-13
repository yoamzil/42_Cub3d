/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:39:49 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/13 19:27:51 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	store_north(t_game *game, char **map, int i)
{
	int		j;
	int		k;
	char	**tmp;

	j = 3;
	k = 0;
	tmp = ft_split(map[i], ' ');
	if (tab_counter(tmp) != 2)
		error();
	game->no = ft_strdup(tmp[1]);
	free_tab(tmp);
}

void	store_south(t_game *game, char **map, int i)
{
	int		j;
	int		k;
	char	**tmp;

	j = 3;
	k = 0;
	tmp = ft_split(map[i], ' ');
	if (tab_counter(tmp) != 2)
		error();
	game->so = ft_strdup(tmp[1]);
	free_tab(tmp);
}

void	store_west(t_game *game, char **map, int i)
{
	int		j;
	int		k;
	char	**tmp;

	j = 3;
	k = 0;
	tmp = ft_split(map[i], ' ');
	if (tab_counter(tmp) != 2)
		error();
	game->we = ft_strdup(tmp[1]);
	free_tab(tmp);
}

void	store_east(t_game *game, char **map, int i)
{
	int		j;
	int		k;
	char	**tmp;

	j = 3;
	k = 0;
	tmp = ft_split(map[i], ' ');
	if (tab_counter(tmp) != 2)
		error();
	game->ea = ft_strdup(tmp[1]);
	free_tab(tmp);
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
