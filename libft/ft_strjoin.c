/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:04:23 by huakbas           #+#    #+#             */
/*   Updated: 2024/09/13 15:04:24 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*pointer;
	unsigned int	s1_length;
	unsigned int	s2_length;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	pointer = malloc(s1_length + s2_length + 1);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		pointer[i++] = *s1++;
	while (*s2)
		pointer[i++] = *s2++;
	pointer[i] = 0;
	return (pointer);
}
