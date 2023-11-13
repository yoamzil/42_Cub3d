/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:53:47 by omakran           #+#    #+#             */
/*   Updated: 2023/11/13 20:04:53 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

#define BPP sizeof(int)


int	intialize_window(void)
{
	mlx_t		*win;
	mlx_image_t	*img;

	win = mlx_init(800, 600, "cub3D", true);
	if (!win)
	{
		ft_putstr_fd("Error Initializing MLX!.\n", 2);
		exit (EXIT_FAILURE);
	}
	img = mlx_new_image(win, 128, 128);
	ft_memset(img->pixels, 255, img->width * img->height * BPP);
	mlx_image_to_window(win, img, 0, 0);
	mlx_loop(win);
	mlx_terminate(win);
	return (EXIT_SUCCESS);
}

