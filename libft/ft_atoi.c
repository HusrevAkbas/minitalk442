/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:58:33 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/01 18:41:54 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	is_n;

	if (!str)
		return (0);
	a = 0;
	is_n = -1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (!ft_isdigit(str[0]) && !ft_isdigit(str[1]))
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_n *= -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		b = *str - 48;
		a = a * 10 - b;
		str++;
	}
	return (is_n * a);
}
