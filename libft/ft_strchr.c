/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:09:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/12/02 15:54:32 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	b;

	i = 0;
	b = (char)c;
	while (i <= ft_strlen(s))
	{
		if (s[i] == b)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Youness is the goat";
	printf("%s", ft_strchr(str, 'i'));
	return (0);
}
*/