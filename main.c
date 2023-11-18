/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/17 11:12:44 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**read_map(char *filepath)
{
	int		fd;
	char	*line;
	char	*accumulator;
	char	*temp_holder;
	char	**map_array;

	accumulator = ft_strdup("");
	fd = open(filepath, O_RDONLY);
	line = get_next_line(fd);
	if (!line || fd == -1)
		return (NULL);
	while (line)
	{
		temp_holder = accumulator;
		accumulator = ft_strjoin(temp_holder, line);
		free(line);
		free(temp_holder);
		line = get_next_line(fd);
	}
	has_double_newline(accumulator);
	map_array = ft_split(accumulator, '\n');
	free(accumulator);
	close(fd);
	return (map_array);
}

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

int	main(int ac, char **av)
{
	t_game	game;
	int		i;
	int		row;

	ft_bzero(&game, sizeof(t_game));
	i = 6;
	row = 0;
	if (ac == 2)
	{
		game.file = read_map(av[1]);
		if (!game.file)
			error();
		while (game.file[row])
			row++;
		if (game.file[i] && row > 6 && is_valid_map(&game, i)
			&& is_valid_arg(av[1]))
		{
			store_textures(&game, game.file);
			has_right_rgb(game);
			init_variables(&game);
			get_player_position(&game);
			start(&game);
		}
		else
			error();
	}
}
