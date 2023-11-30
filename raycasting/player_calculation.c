/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:02:16 by omakran           #+#    #+#             */
/*   Updated: 2023/11/30 23:53:27 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

float	to_radian(float nb)
{
	return ((nb * M_PI) / 180);
}

void	direction_of_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'W')
				game->direction = WE;
			else if (game->map[y][x] == 'E')
				game->direction = EA;
			else if (game->map[y][x] == 'N')
				game->direction = NO;
			else if (game->map[y][x] == 'S')
				game->direction = SO;
			x++;
		}
		y++;
	}
}
char	get_the_direct_of_player(t_game *game)
{
	if (game->direction == WE)
	{
		game->player_pos->rotation_angle = to_radian(0);
		return ('W');
	}

	if (game->direction == NO)
	{
		game->player_pos->rotation_angle = to_radian(270);
		return ('N');	
	}
	if (game->direction == SO)
	{
		game->player_pos->rotation_angle = to_radian(90);
		return ('S');		
	}
	game->player_pos->rotation_angle = to_radian(180);
	return ('E');
}
void	get_player_position(t_game *game)
{
	int		i;
	char	dir;

	dir = get_the_direct_of_player(game);
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
	game->player_pos->y = (float)(i * SQUAR_SIZE + (SQUAR_SIZE / 2) + 1);
	game->player_pos->x = (float)(((ft_strchr(game->map[i], dir))
				- game->map[i]) * SQUAR_SIZE + (SQUAR_SIZE / 2) + 1);
}
