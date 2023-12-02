/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:43:05 by yoamzil           #+#    #+#             */
/*   Updated: 2023/12/02 15:55:36 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Shakeitoff";
	printf("%d", ft_strlen(str));
	return (0);
}
*/