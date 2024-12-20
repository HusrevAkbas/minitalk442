/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:32 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/20 16:46:24 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bin(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(20);
		i--;
	}
}

void	send_msg(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_bin(str[i], pid);
		i++;
	}
	char_to_bin('\0', pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	pid = ft_atoi(argv[1]);
	if (argc < 3)
	{
		ft_printf("You have to give a process id and a message to send.\n Only one message at a time!!\n");
		return (0);
	}
	ft_printf("%s\n", argv[2]);
	send_msg(argv[2], pid);
	//kill(pid, SIGXFSZ);
	//kill(pid, SIGTERM);
	return (0);
}
