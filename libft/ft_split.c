/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:47:59 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/07 17:01:50 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int	i;
	int	word_count;

	if (ft_strlen(s) == 0)
		return (0);
	i = 0;
	word_count = 0;
	if (s[i] != c)
		word_count++;
	while (s[i +1])
	{
		if (s[i] == c && s[i + 1] != c)
			word_count++;
		i++;
	}
	return (word_count);
}

static char	**clear_mem(char **pointer, int i)
{
	while (i >= 0)
	{
		free(pointer[i]);
		i--;
	}
	free(pointer);
	pointer = NULL;
	return (pointer);
}

void	clear_split(char **pointer)
{
	int	i;

	if (!pointer || !pointer[0])
		return ;
	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
	pointer = NULL;
}

static char	**split(char **pointer, char *s, char c, size_t word_count)
{
	size_t	i;
	size_t	count_c;
	size_t	word_index;

	if (!s && !*s)
		return (NULL);
	i = 0;
	word_index = 0;
	while (word_count > word_index)
	{
		count_c = i;
		while (s[i] != 0 && s[i] == c)
		{
			count_c++;
			i++;
		}
		while (s[i] != 0 && s[i] != c)
			i++;
		pointer[word_index] = ft_substr(s, count_c, i - count_c);
		if (pointer[word_index] == NULL)
			return (clear_mem(pointer, word_index));
		word_index++;
	}
	pointer[word_count] = NULL;
	return (pointer);
}

char	**ft_split(char const *s, char c)
{
	char	**pointer;
	char	*str;
	size_t	word_count;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	word_count = count_words(str, c);
	pointer = (char **) malloc((word_count + 1) * sizeof(char *));
	if (pointer == NULL)
		return (NULL);
	if (word_count == 0)
	{
		pointer[word_count] = NULL;
		return (pointer);
	}
	return (split(pointer, str, c, word_count));
}
