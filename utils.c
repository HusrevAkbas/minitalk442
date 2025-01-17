/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:38 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/17 14:58:11 by huakbas          ###   ########.fr       */
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

unsigned char	*print_result(unsigned char *str, int i, int *bits, int *pid)
{
	kill(*pid, SIGUSR2);
	write(1, str, i);
	write(1, "\n", 1);
	if (!ft_strncmp((char *)str, "exit", i))
	{
		free(str);
		return (NULL);
	}
	*bits = 0;
	free(str);
	str = ft_calloc(BUFF_SIZE + 1, 1);
	*pid = 0;
	return (str);
}

unsigned char	*set_str(unsigned char *str, char *bin, int *bits, int *pid)
{
	unsigned char	*new;
	int				i;

	i = *bits / 8 - 1;
	str[i] = ft_atoi_base(bin, "01");
	if (str[i] == 0)
		str = print_result(str, i, bits, pid);
	if (i != 0 && i % BUFF_SIZE == 0)
	{
		new = ft_calloc(i + BUFF_SIZE + 1, 1);
		if (!new)
		{
			free(str);
			return (NULL);
		}
		ft_memmove(new, str, i + 1);
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
