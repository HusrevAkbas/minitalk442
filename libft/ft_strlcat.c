/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:43:22 by huakbas           #+#    #+#             */
/*   Updated: 2024/09/12 16:43:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_length;
	size_t	dst_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	i = 0;
	if (size == 1 && dst_length == 1)
		dst[1] = '\0';
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && size - j > dst_length + 1)
	{
		dst[i++] = src[j++];
	}
	if (size != 0)
		dst[i] = '\0';
	if (size < dst_length)
		return (size + src_length);
	return (src_length + dst_length);
}
