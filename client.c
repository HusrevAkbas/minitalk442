/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:32 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/25 10:34:30 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	feedback_handler(int signum, siginfo_t *info, void *data)
{
	static int	i = 0;
	(void) signum;
	(void) info;
	(void) data;
	i++;
	ft_printf("%s%i\n", "message printed: ", i);
}

void	char_to_bin(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(100);
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

void	send_msg(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % BUFF_SIZE == 0 && (int) ft_strlen(str) >= i + BUFF_SIZE)
			char_to_bin('1', pid);
		else if (i % BUFF_SIZE == 0)
			char_to_bin('0', pid);
		char_to_bin(str[i], pid);
		i++;
	}
	char_to_bin('\0', pid);
}

int	main(int argc, char **argv)
{
	int			pid;
	t_sigaction	sa_feedback;
	sigset_t	set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sa_feedback.sa_flags = SA_RESTART;
	sa_feedback.sa_mask = set;
	sa_feedback.sa_sigaction = &feedback_handler;
	if (sigaction(SIGUSR1, &sa_feedback, NULL) == -1)
		return (0);
	if (argc != 3)
	{
		ft_printf("You have to give a process id and a message to send.\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	//ft_printf("%s | pid: %i\n", argv[2], getpid());
	while (1)
	{
		send_msg(argv[2], pid);
		pause();
		sleep(7);
	}
	sleep(1);
	return (0);
}
