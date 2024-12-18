/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:04:54 by huakbas           #+#    #+#             */
/*   Updated: 2024/09/10 13:04:56 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	move_forward(unsigned char *destination,
						unsigned char *source, size_t n)
{
	while (n > 0)
	{
		*destination++ = *source++;
		n--;
	}
}

static void	move_backward(unsigned char *destination,
						unsigned char *source, size_t n)
{
	while (n > 0)
	{
		n--;
		*destination-- = *source--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	if (dest == src)
		return (dest);
	if (dest - src < 0)
		move_forward(destination, source, n);
	else
		move_backward(&destination[n - 1], &source[n - 1], n);
	return (dest);
}
