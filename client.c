/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:32 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/19 18:30:47 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bin(char *str, int pid)
{
	int	i;

	i = 7;
	ft_printf("%d, %c\n", str[0], str[0]);
	while (i >= 0)
	{
		ft_printf("%i", (str[0] >> i) & 1);
		if (((str[0] >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(20);
		i--;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int	pid;
	pid = ft_atoi(argv[1]);
	if (argc < 3)
		return (0);
	char_to_bin(argv[2], pid);
	kill(pid, SIGXFSZ);
	//kill(pid, SIGTERM);
	return (0);
}
