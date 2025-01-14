/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/14 19:10:11 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	*g_str;

void	handler(int signum, siginfo_t *info, void *data)
{
	static int	bits = 0;
	static int	pid = 0;
	static char	bin[9];
	static int	i = 0;

	(void) data;
	if (!pid)
	{
		pid = info->si_pid;
		bits = 0;
		kill(pid, SIGUSR1);
		return ;
	}
	if (pid != info->si_pid)
		return ;
	if (signum == SIGUSR1)
		bin[bits] = '1';
	else
		bin[bits] = '0';
	bits++;
	if (bits == 8)
		g_str = set_str(g_str, bin, &bits, &pid, &i);
	if (!g_str)
		exit(0);
	if (pid)
		kill(pid, SIGUSR1);
}

int	main(void)
{
	t_sigaction	sa_usr1;
	sigset_t	set;

	g_str = malloc(BUFF_SIZE + 1);
	if (!g_str)
		return (-1);
	print_pid();
	set_sa(&sa_usr1, &set);
	sa_usr1.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa_usr1, NULL);
	sigaction(SIGUSR2, &sa_usr1, NULL);
	while (1)
		pause();
	return (0);
}
