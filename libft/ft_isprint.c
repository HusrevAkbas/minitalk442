/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:20 by huakbas           #+#    #+#             */
/*   Updated: 2024/09/03 15:59:24 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c < ' ' || c > '~')
		return (0);
	else
		return (1);
}

/*
#include <stdio.h>
int	main(int ac, char *av[])
{
	int	r;

	if (ac == 2)
	{
		r = ft_c_printable(av[1]);
		printf("%d", r);
	}
	return (42);
}*/