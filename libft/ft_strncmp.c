/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:31:29 by yoamzil           #+#    #+#             */
/*   Updated: 2023/11/14 16:43:49 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	j = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (str2[j] && str2[j] == ' ')
		j++;
	while (i < n && (str1[i] != '\0' || str2[j] != '\0'))
	{
		if (str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else if (str1[i] > str2[j])
			return (1);
		else if (str1[i] < str2[j])
			return (-1);
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	char	s1[] = "howa da";
	char	s2[] = "howa da";
	printf("%d", ft_strncmp(s1, s2, 4));
	return (0);
}
*/