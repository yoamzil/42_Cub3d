/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_the_all_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:56:08 by omakran           #+#    #+#             */
/*   Updated: 2023/12/04 09:36:32 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_the_double_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
}

void	free_the_all_data(t_game *game)
{
	free_the_double_arr(game->map);
}
