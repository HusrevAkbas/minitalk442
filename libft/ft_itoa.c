/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:38:43 by huakbas           #+#    #+#             */
/*   Updated: 2024/09/18 13:38:45 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chars(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	set_mem(char *pointer, int n, int index)
{
	int	last_digit;

	last_digit = n % 10;
	if (n >= 10)
		set_mem(pointer, n / 10, index - 1);
	pointer[index] = '0' + last_digit;
}

char	*ft_itoa(int n)
{
	char	*pointer;
	int		last_digit;
	int		sign;
	int		count_char;

	sign = 1;
	last_digit = n % 10;
	count_char = count_chars(n);
	if (n < 0)
	{
		sign *= -1;
		last_digit *= -1;
		count_char += 1;
	}
	pointer = (char *) ft_calloc(count_char + 1, sizeof(char));
	if (pointer == NULL)
		return (NULL);
	if (count_char > 1)
		set_mem(pointer, (n / 10) * sign, count_char - 2);
	if (sign < 0)
		pointer[0] = '-';
	pointer[count_char -1] = '0' + last_digit;
	pointer[count_char] = '\0';
	return (pointer);
}
