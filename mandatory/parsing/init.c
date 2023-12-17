/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:06:56 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/14 19:33:19 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	longest_row(t_game *game)
{
	int		row;
	size_t	max;

	row = 0;
	max = 0;
	while (game->file[row])
		row++;
	game->height = row - 6;
	row = 0;
	while (row < game->height)
	{
		if (ft_strlen(game->map[row]) > max)
			max = ft_strlen(game->map[row]);
		row++;
	}
	return (max);
}

void	init_variables(t_game *game)
{
	game->map = game->file + 6;
	game->width = longest_row(game);
}
