/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:32 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/14 14:20:37 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_message;

void	handler(int signum, siginfo_t *info, void *data)
{
	static int	bits = 0;
	int			i;
	int			b;

	(void) data;
	if (signum == SIGUSR2)
	{
		write(1, "Message received by server!", 28);
		exit(0);
	}
	i = bits / 8;
	b = 7 - (bits % 8);
	if (!g_message[i])
	{
		kill(info->si_pid, SIGUSR2);
		if (!g_message[i] && b == 0)
			exit(0);
	}
	else if (((g_message[i] >> b) & 1) == 1)
		kill(info->si_pid, SIGUSR1);
	else
		kill(info->si_pid, SIGUSR2);
	bits++;
}

int	main(int argc, char **argv)
{
	int			pid;
	t_sigaction	sa_feedback;

	sa_feedback.sa_flags = SA_SIGINFO;
	sa_feedback.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa_feedback, NULL);
	sigaction(SIGUSR2, &sa_feedback, NULL);
	if (argc != 3)
		return (ft_printf("./client <PROCESS ID> <MESSAGE>"));
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("./client <PROCESS ID> <MESSAGE>"));
	g_message = argv[2];
	kill(pid, SIGUSR1);
	while (1)
	{
		pause();
	}
	return (0);
}
