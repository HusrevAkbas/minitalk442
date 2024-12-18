/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/18 15:05:38 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	printf("this is USR1 from user %d\n", signum);
}

void	handler2(int signum)
{
	printf("this is USR2 from user %d\n", signum);
}

void	ignore_kill(int signum)
{
	printf("kill signal from user is ignored %d\n", signum);
}

int main(void)
{
	int		pid;
	char	*pidchar;
	t_sigaction	sa_usr1;
	t_sigaction	sa_usr2;

	pid = getpid();
	pidchar = ft_itoa(pid);
	write(1, pidchar, ft_strlen(pidchar));
	write(1, "\n", 1);
	sa_usr1.sa_flags = SA_RESTART;
	sa_usr1.sa_handler = &handler;
	sigaction(SIGUSR1, &sa_usr1, NULL);
	
	sa_usr2.sa_flags = SA_RESTART;
	sa_usr2.sa_handler = &handler2;
	sigaction(SIGUSR2, &sa_usr2, NULL);
	
	while (1)
	{
		pause();
	}
	free(pidchar);
	return (0);
}
