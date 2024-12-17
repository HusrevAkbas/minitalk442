/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/17 18:18:48 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	printf("signal handler: not allowed %d\n", signum);
}

int main(int argc, char const *argv[])
{
	t_sigaction	sa;
	sigset_t	*set;
	//int	num;

	(void) argc;
	(void) argv;
	set = malloc(sizeof(sigset_t));
	sigemptyset(set);
	sigaddset(set, SIGUSR1);
	sigaddset(set, SIGUSR2);
	printf("%d\n", sigismember(set, SIGSTOP));
	printf("%d\n", sigismember(set, SIGUSR1));
	sa.sa_handler = &handler;
	sa.sa_mask = *set;
	sa.sa_flags = SA_NODEFER;
	sigaction(SIGUSR2, &sa, NULL);
	//signal(SIGTSTP, &handler);
	free(set);
	return (0);
}
