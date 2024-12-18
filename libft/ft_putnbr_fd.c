/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:23:39 by huakbas           #+#    #+#             */
/*   Updated: 2024/09/19 14:23:40 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

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

static void	set_num(char *str, int n, int index)
{
	int	last_digit;

	last_digit = n % 10;
	if (n >= 10)
		set_num(str, n / 10, index - 1);
	str[index] = '0' + last_digit;
}

static void	itoa(char *str, int n)
{
	int	last_digit;
	int	sign;
	int	count_char;

	sign = 1;
	last_digit = n % 10;
	count_char = count_chars(n);
	if (n < 0)
	{
		sign *= -1;
		last_digit *= -1;
		count_char++;
	}
	if (sign < 0)
		str[0] = '-';
	if ((count_char > 2 && sign < 0) || (count_char > 1 && sign > 0))
		set_num(str, (n / 10) * sign, count_char - 2);
	str[count_char - 1] = '0' + last_digit;
	str[count_char] = '\0';
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num_as_str[12];

	itoa(num_as_str, n);
	ft_putstr_fd(num_as_str, fd);
}
