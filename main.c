/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/10 10:24:41 by yoamzil          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	i = 6;
	if (ac == 2)
	{
		game.map = read_map(av[1]);
		if (game.map && is_valid_map(&game, i) && is_valid_arg(av[1]))
		{
			printf("Valid Map\n");
		}
		else
		{
			printf("Invalid Map\n");
		}
	}
}
