/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase_ul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:58:45 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/25 15:13:11 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_base_valid(const char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

static int	count_chars(unsigned long num, const char *base)
{
	int				count;
	unsigned long	base_length;

	count = 1;
	base_length = (unsigned long) ft_strlen(base);
	while (num >= base_length)
	{
		count++;
		num = num / base_length;
	}
	return (count);
}

static void	ft_put(char *str, unsigned long nbr, const char *base, int i)
{
	int				remainder;
	unsigned long	base_length;

	base_length = (unsigned long) ft_strlen(base);
	if (nbr >= (unsigned long) ft_strlen(base))
		ft_put(str, nbr / base_length, base, i - 1);
	remainder = nbr % base_length;
	str[i] = base[remainder];
}

char	*ft_itobase_ul(unsigned long nbr, const char *base)
{
	char			*str;
	unsigned long	base_length;
	int				last_d;
	int				char_count;

	if (!base)
		return (0);
	base_length = is_base_valid(base);
	if (base_length == 0)
		return (0);
	char_count = count_chars(nbr, base);
	last_d = nbr % base_length;
	nbr = nbr / base_length;
	str = (char *) ft_calloc(char_count + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (char_count > 1)
		ft_put(str, nbr, base, char_count - 2);
	str[char_count - 1] = base[last_d];
	return (str);
}
