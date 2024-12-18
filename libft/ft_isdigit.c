/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:04 by huakbas           #+#    #+#             */
/*   Updated: 2024/09/03 15:59:11 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	r;

	if (argc > 1)
	{
		r = ft_str_is_numeric(argv[1]);
		printf("%d", r);
	}
	return (42);
}*/