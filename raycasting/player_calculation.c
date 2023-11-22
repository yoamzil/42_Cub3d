/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:02:16 by omakran           #+#    #+#             */
/*   Updated: 2023/11/21 15:16:03 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

float	to_radian(float nb)
{
	return ((nb * M_PI) / 180);
}

void	set_direction(t_game *game)
{
	game->player_pos->rotation_angle =  (M_PI / 2);
	// if (game->direction == 'N')
	// 	game->player_pos->rotation_angle = to_radian(0);
	// else if (game->direction == 'S')
	// 	game->player_pos->rotation_angle = to_radian(180);
	// else if (game->direction == 'E')
	// 	game->player_pos->rotation_angle = to_radian(90);
	// else if (game->direction == 'W')
	// 	game->player_pos->rotation_angle = to_radian(270);
}

char	direction_of_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
					game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->direction = game->map[i][j];
				break ;
			}
			j++;
			continue ;
		}
		i++;
	}
	return (game->direction);
}

void	get_player_position(t_game *game)
{
	int		i;
	char	dir;

	game->player_pos = malloc(sizeof(t_player_x_y));
	dir = direction_of_player(game);
	set_direction(game);
	i = 0;
	while (game->map[i])
	{
		if (!ft_strchr(game->map[i], dir))
		{
			i++;
			continue ;
		}
		break ;
	}
	game->player_pos->y = (float)(i * SQUAR_SIZE + (SQUAR_SIZE / 2));
	game->player_pos->x = (float)(((ft_strchr(game->map[i], dir)) - \
		game->map[i]) * SQUAR_SIZE + (SQUAR_SIZE / 2));
}
