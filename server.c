/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/14 14:19:57 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *data)
{
	static int	bits = 0;
	static int	pid = 0;
	static char	bin[9];

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
		print_result(bin, &bits, &pid);
	if (pid)
		kill(pid, SIGUSR1);
}

int	main(void)
{
	t_sigaction	sa_usr1;
	sigset_t	set;

	print_pid();
	set_sa(&sa_usr1, &set);
	sa_usr1.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa_usr1, NULL);
	sigaction(SIGUSR2, &sa_usr1, NULL);
	while (1)
	{
		sleep(1);
	}
	exit_p(0);
	return (0);
}
