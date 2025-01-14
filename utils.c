/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:38 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/14 14:20:21 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_sa(t_sigaction *sa1, sigset_t *set)
{
	(*sa1).sa_flags = SA_SIGINFO;
	sigemptyset(set);
	sigaddset(set, SIGUSR1);
	sigaddset(set, SIGUSR2);
	(*sa1).sa_mask = *set;
}

void	print_result(char *bin, int *bits, int *pid)
{
	unsigned char	c;

	*bits = 0;
	c = ft_atoi_base(bin, "01");
	if (c == 0)
	{
		kill(*pid, SIGUSR2);
		write(1, "\n", 1);
		*pid = 0;
	}
	write(1, &c, 1);
}

void	print_pid(void)
{
	int			pid;
	char		*pidchar;

	pid = getpid();
	pidchar = ft_itoa(pid);
	write(1, pidchar, ft_strlen(pidchar));
	write(1, "\n", 1);
	free(pidchar);
}
