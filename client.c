/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:32 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/18 15:15:18 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	size= 31;
	int	num = 7;
	int	pid;
	int i = 0;
(void) argc;
	pid = ft_atoi(argv[1]);
	while (i < 10)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		kill(pid, SIGUSR2);
		i++;
	}
	while (0 <= size)
	{
		printf("%i", (num >> size) & 1);
		size--;
	}
	return (0);
}
