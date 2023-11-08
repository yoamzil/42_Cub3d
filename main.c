/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/08 12:17:08 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	first_empty_line(char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\n')
	{
		printf("Error\nEmpty Line Found");
		exit(1);
	}
	return (0);
}

int	has_double_newline(char *map)
{
	while (*map)
	{
		if (*map == '\n' && *(map + 1) == '\n')
		{
			printf("Error\nDouble New Line Found\n");
			exit(1);
		}
		map++;
	}
	return (0);
}

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
	first_empty_line(accumulator);
	has_double_newline(accumulator);
	map_array = ft_split(accumulator, '\n');
	free(accumulator);
	close(fd);
	return (map_array);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game.map = read_map(av[1]);
		if (is_valid_map(&game) && is_valid_arg(av[1]))
		{
			printf("Valid Map\n");	
		}
		else
		{
			printf("Invalid Map\n");
		}
	}
}
