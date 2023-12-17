/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:03 by omakran           #+#    #+#             */
/*   Updated: 2023/12/17 13:47:36 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

int	is_within_window(int x, int y)
{
	return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}
