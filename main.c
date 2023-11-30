/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/30 23:58:12 by omakran          ###   ########.fr       */
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
void	set_up(t_game *game)
{
	game->player_pos->fov_angle = 60 * (M_PI / 180); // TO CONVERT THE ANGLE TO RADIANS
	game->player_pos->wall_strip_width = 30;
	game->player_pos->num_rays = WIDTH / game->player_pos->wall_strip_width;
	
}
t_game	*init_data(t_game *game)
{

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player_pos = (t_player_x_y *)malloc(sizeof(t_player_x_y));

	if (!game->player_pos)
		return (NULL);
	game->hori = (t_hori *)malloc(sizeof(t_hori));
	if (!game->hori)
		return (NULL);
	game->cast = (t_ray_cast *)malloc(sizeof(t_ray_cast));
	if (!game->cast)
		return (NULL);
	game->ver = (t_ver *)malloc(sizeof(t_ver));
	if (!game->ver)
		return (NULL);
	game->textrs = (t_textrs *)malloc(sizeof(t_textrs));
	if (!game->textrs)
		return (NULL);
	game->player_pos->fov_angle = to_radian(60);
	return (game);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		i;
	int		row;

	game = NULL;
	// ft_bzero(game, sizeof(t_game));
	game = init_data(game);
	// 	printf("%p\n", game->player_pos);
	// exit(1);
	i = 6;
	row = 0;
	if (ac == 2)
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
}
