/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:10:26 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/07 15:38:13 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pointer;
	size_t	i;
	size_t	div;

	if (nmemb < 1 || size < 1)
	{
		pointer = (void *) malloc(0);
		if (!pointer)
			return (NULL);
		return (pointer);
	}
	div = ULONG_MAX / nmemb;
	if (div < size)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
		pointer[i++] = 0;
	return ((void *) pointer);
}
