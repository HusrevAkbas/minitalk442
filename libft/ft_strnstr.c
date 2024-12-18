/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:51 by huakbas           #+#    #+#             */
/*   Updated: 2024/09/03 15:59:54 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare(char *str1, char *str2, size_t i, size_t len)
{
	if (i + ft_strlen(str2) > len)
		return (-1);
	return (ft_strncmp(str1, str2, ft_strlen(str2)));
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*new_big;
	char	*new_little;
	size_t	i;

	i = 0;
	new_big = (char *) big;
	new_little = (char *) little;
	if (ft_strlen (little) == 0)
		return (new_big);
	while (i < len && new_big[i] != 0)
	{
		if (new_big[i] == new_little[0])
		{
			if (compare(&new_big[i], new_little, i, len) == 0)
				return (&new_big[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%d", ft_strncmp(av[1], av[2], atoi(av[3])));
	}
	return (42);
}*/
