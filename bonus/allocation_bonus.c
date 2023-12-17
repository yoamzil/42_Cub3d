/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:33:26 by yoamzil           #+#    #+#             */
/*   Updated: 2023/12/17 13:47:49 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

t_game	*allocate_game_memory(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	return (game);
}

int	allocate_player_memory(t_game *game)
{
	game->player_pos = (t_player_x_y *)malloc(sizeof(t_player_x_y));
	if (!game->player_pos)
		return (0);
	return (1);
}

int	allocate_other_structures(t_game *game)
{
	game->hori = (t_hori *)malloc(sizeof(t_hori));
	if (!game->hori)
		return (0);
	game->cast = (t_ray_cast *)malloc(sizeof(t_ray_cast));
	if (!game->cast)
		return (0);
	game->ver = (t_ver *)malloc(sizeof(t_ver));
	if (!game->ver)
		return (0);
	game->textrs = (t_textrs *)malloc(sizeof(t_textrs));
	if (!game->textrs)
		return (0);
	game->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!game->mouse)
		return (0);
	return (1);
}

t_game	*init_data(t_game *game)
{
	game = allocate_game_memory();
	if (!game)
		return (NULL);
	if (!allocate_player_memory(game))
		return (NULL);
	if (!allocate_other_structures(game))
		return (NULL);
	game->player_pos->fov_angle = to_radian(60);
	game->textrs->ea_t = malloc(sizeof(mlx_texture_t));
	game->textrs->no_t = malloc(sizeof(mlx_texture_t));
	game->textrs->so_t = malloc(sizeof(mlx_texture_t));
	game->textrs->we_t = malloc(sizeof(mlx_texture_t));
	return (game);
}
