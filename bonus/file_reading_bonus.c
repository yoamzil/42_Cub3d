/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:42:35 by yoamzil           #+#    #+#             */
/*   Updated: 2023/12/17 13:47:52 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

char	*read_file_contents(char *filepath)
{
	int		fd;
	char	*line;
	char	*accumulator;
	char	*temp_holder;

	accumulator = ft_strdup("");
	fd = open(filepath, O_RDONLY);
	line = get_next_line(fd);
	if (!line || fd == -1)
	{
		free(accumulator);
		return (NULL);
	}
	while (line)
	{
		temp_holder = accumulator;
		accumulator = ft_strjoin(temp_holder, line);
		free(line);
		free(temp_holder);
		line = get_next_line(fd);
	}
	close(fd);
	return (accumulator);
}

char	**split_file_contents(char *contents)
{
	char	**map_array;

	has_double_newline(contents);
	map_array = ft_split(contents, '\n');
	free(contents);
	return (map_array);
}

char	**read_map(char *filepath)
{
	char	*contents;
	char	**map_array;

	contents = read_file_contents(filepath);
	if (!contents)
		return (NULL);
	map_array = split_file_contents(contents);
	return (map_array);
}
