/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:24:03 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/29 15:04:10 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *str1, char *str2, size_t size)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	dst_length;

	if (!str1)
		return (NULL);
	dst_length = ft_strlen(str1);
	i = 0;
	new = malloc(size + dst_length + 1);
	if (new)
	{
		while (str1[i])
		{
			new[i] = str1[i];
			i++;
		}
		j = 0;
		while (str2[j] && j < size)
			new[i++] = str2[j++];
		new[i] = 0;
	}
	return (new);
}
