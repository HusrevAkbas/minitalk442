/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:32 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/17 14:56:01 by huakbas          ###   ########.fr       */
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
		usleep(100);
		if (!g_message[i] && b == 0)
			exit(0);
	}
	else if (((g_message[i] >> b) & 1) == 1)
		kill(info->si_pid, SIGUSR1);
	else
		kill(info->si_pid, SIGUSR2);
	bits++;
}

int	check_pid(char *pid)
{
	int	i;
	int	pidnum;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (-1);
		i++;
	}
	if (i > 10)
		return (-1);
	if (i == 10)
	{
		if (pid[0] > '2')
			return (-1);
		if (pid[0] == '2' && ft_atoi(&pid[1]) > 147483648)
			return (-1);
	}
	pidnum = ft_atoi(pid);
	if (pidnum <= 0)
		return (-1);
	return (pidnum);
}

int	main(int argc, char **argv)
{
	int			pid;
	t_sigaction	sa_feedback;

	sa_feedback.sa_flags = SA_SIGINFO;
	sa_feedback.sa_sigaction = &handler;
	sigemptyset(&sa_feedback.sa_mask);
	sigaction(SIGUSR1, &sa_feedback, NULL);
	sigaction(SIGUSR2, &sa_feedback, NULL);
	if (argc != 3)
		return (ft_printf("./client <PROCESS ID> <MESSAGE>"));
	pid = check_pid(argv[1]);
	if (pid <= 0)
		return (ft_printf("./client <PROCESS ID> <MESSAGE>"));
	g_message = argv[2];
	kill(pid, SIGUSR1);
	while (1)
		pause();
	return (0);
}
