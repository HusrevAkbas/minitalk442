/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:04:23 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/07 15:27:05 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pointer;
	unsigned int	s_length;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if (start >= s_length)
	{
		pointer = ((char *) ft_calloc(1, sizeof(char)));
		if (!pointer)
			return (NULL);
		return (pointer);
	}
	if (s_length <= start + len)
		len = s_length - start;
	pointer = (char *) ft_calloc(len + 1, sizeof(char));
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (len > i && s[start])
		pointer[i++] = s[start++];
	pointer[i] = 0;
	return (pointer);
}
