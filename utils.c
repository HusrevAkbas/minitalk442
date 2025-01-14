/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:38 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/14 19:31:15 by huakbas          ###   ########.fr       */
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

unsigned char	*set_str(unsigned char *str, char *bin, int *bits, int *pid, int *i)
{
	unsigned char	*new;
	int				total;

	*bits = 0;
	str[*i] = ft_atoi_base(bin, "01");
	if (str[*i] == 0)
	{
		kill(*pid, SIGUSR2);
		write(1, str, *i);
		write(1, "\n", 1);
		*i = 0;
		if (!ft_strncmp((char *)str, "exit", 4))
		{
			free(str);
			return (NULL);
		}
		free(str);
		str = malloc(BUFF_SIZE + 1);
		*pid = 0;
		return (str);
	}
	*i += 1;
	if (*i % BUFF_SIZE == 0)
	{
		total = ft_strlen((char *)str) + BUFF_SIZE + 1;
		new = malloc(total);
		if (!new)
		{
			free(str);
			return (NULL);
		}
		ft_memmove(new, str, ft_strlen((char *)str));
		free(str);
		return (new);
	}
	return (str);
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
