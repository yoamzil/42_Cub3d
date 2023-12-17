/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/12/17 13:47:56 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	set_up(t_game *game)
{
	game->player_pos->move_speed = 3.5;
	game->player_pos->fov_angle = 60 * (M_PI / 180);
	game->player_pos->wall_strip_width = 30;
	game->player_pos->num_rays = WIDTH / game->player_pos->wall_strip_width;
	game->mouse->x = 0;
	game->mouse->y = 0;
}

void	main_helper(t_game *game, char **av, int i, int row)
{
	game->file = read_map(av[1]);
	if (!game->file)
		error();
	while (game->file[row])
		row++;
	if (game->file[i] && row > 6 && is_valid_map(game, i)
		&& is_valid_arg(av[1]))
	{
		store_textures(game, game->file);
		has_right_rgb(game);
		init_variables(game);
		start(game);
	}
	else
		error();
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		i;
	int		row;

	game = NULL;
	game = init_data(game);
	if (!game)
	{
		free_the_all_data(game);
		exit (EXIT_FAILURE);
	}
	i = 6;
	row = 0;
	if (ac == 2)
	{
		main_helper(game, av, i, row);
	}
	else
		error();
	return (0);
}
