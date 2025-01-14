/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:32 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/14 13:35:16 by huakbas          ###   ########.fr       */
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
	b = bits % 8;
ft_printf("i: %i b: %i  \n", i, b);
	if (!g_message[i] && b == 7)
		exit(0);
	if (!g_message[i])
		kill(info->si_pid, SIGUSR2);
	else if (((g_message[i] >> b) & 1) == 1)
	{
		ft_printf("bit ? %i\n", ((g_message[i] >> b) & 1));
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);
	bits++;
}

// void	char_to_bin(char c, int pid)
// {
// 	int	i;

// 	i = 7;
// 	while (i >= 0)
// 	{
// 		usleep(100);
// 		if (((c >> i) & 1) == 1)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		i--;
// 	}
// }

// void	send_msg(char *str, int pid)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (i % BUFF_SIZE == 0 && (int) ft_strlen(str) >= i + BUFF_SIZE)
// 			char_to_bin('1', pid);
// 		else if (i % BUFF_SIZE == 0)
// 			char_to_bin('0', pid);
// 		char_to_bin(str[i], pid);
// 		i++;
// 	}
// 	char_to_bin('\0', pid);
// }

int	main(int argc, char **argv)
{
	int			pid;
	t_sigaction	sa_feedback;

	sa_feedback.sa_flags = SA_SIGINFO;
	sa_feedback.sa_sigaction = &handler;
	sigemptyset(&sa_feedback.sa_mask);
	sigaddset(&sa_feedback.sa_mask, SIGUSR1);
	sigaddset(&sa_feedback.sa_mask, SIGUSR2);
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
