/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/11 15:20:00 by yoamzil          ###   ########.fr       */
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

void    store_floor(t_game *game, char **map, int i)
{
    int j;
    int k;

    j = 2;
    k = 0;
    game->F = malloc(ft_strlen(map[i]) - 3);
    while ((size_t)j < ft_strlen(map[i]))
    {
        game->F[k] = map[i][j];
        k++;
        j++;
    }
}

void    store_ceiling(t_game *game, char **map, int i)
{
    int j;
    int k;

    j = 2;
    k = 0;
    game->C = malloc(ft_strlen(map[i]) - 3);
    while ((size_t)j < ft_strlen(map[i]))
    {
        game->C[k] = map[i][j];
        k++;
        j++;
    }
}

int	main(int ac, char **av)
{
	t_game	game;
	int		i;
	int		height;


    ft_bzero(&game, sizeof(t_game));
	i = 6;
	height = 0;
	if (ac == 2)
	{
		game.map = read_map(av[1]);
		if (!game.map)
			exit(1);
		while (game.map[height])
			height++;
		if (game.map[i] && height > 6 && is_valid_map(&game, i)
			&& is_valid_arg(av[1]))
		{
            printf("Valid Map\n");
            store_textures(&game, game.map);
            printf("%s\n", game.NO);
            printf("%s\n", game.SO);
            printf("%s\n", game.WE);
            printf("%s\n", game.EA);
            printf("%s\n", game.F);
            printf("%s\n", game.C);
        }
		else
		{
			printf("Error\nInvalid Map\n");
			exit (1);
		}
	}
}
