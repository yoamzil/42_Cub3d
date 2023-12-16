/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:49:05 by yoamzil           #+#    #+#             */
/*   Updated: 2023/12/16 16:30:00 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	store_floor(t_game *game, char **map, int i)
{
	char	**tmp;

	tmp = ft_split(map[i], ' ');
	if (tab_counter(tmp) != 2)
		error();
	game->f = ft_strdup(tmp[1]);
	free_tab(tmp);
}

void	store_ceiling(t_game *game, char **map, int i)
{
	char	**tmp;

	tmp = ft_split(map[i], ' ');
	if (tab_counter(tmp) != 2)
		error();
	game->c = ft_strdup(tmp[1]);
	free_tab(tmp);
}

void	get_texture(t_game *game)
{
	game->texture[0] = mlx_load_png(game->no);
	game->texture[1] = mlx_load_png(game->so);
	game->texture[2] = mlx_load_png(game->we);
	game->texture[3] = mlx_load_png(game->ea);
	if (!game->texture[0] || !game->texture[1]
		|| !game->texture[2] || !game->texture[3])
		printf("invalid textures");
}
