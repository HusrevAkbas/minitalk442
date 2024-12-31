/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:38 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/31 13:43:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*init_string(int pid_src)
{
	t_stringholder	*string;

	string = malloc(sizeof(t_stringholder));
	if (!string)
		return (NULL);
	string->str = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!string->str)
	{
		free(string);
		return (NULL);
	}
	ft_bzero(string->bin, 9);
	string->pid_sender = pid_src;
	string->i_bin = 0;
	string->i_str = 0;
	string->is_long = 0;
	string->is_long_set = 0;
	string->is_done = 0;
	string->size = BUFF_SIZE + 1;
	return (string);
}

void	set_sa(t_sigaction *sa1, sigset_t *set)
{
	(*sa1).sa_flags = SA_SIGINFO;
	sigemptyset(set);
	sigaddset(set, SIGUSR1);
	sigaddset(set, SIGUSR2);
	(*sa1).sa_mask = *set;
}

void	extend_str(t_stringholder **strholder)
{
	unsigned char	*middle;

	if (!strholder || !(*strholder))
		return ;
	(*strholder)->is_long = ft_atoi_base((*strholder)->bin, "01") - 48;
	if ((*strholder)->is_long == 1)
	{
		middle = (*strholder)->str;
		(*strholder)->size += BUFF_SIZE;
		(*strholder)->str = ft_calloc((*strholder)->size, 1);
		if (!(*strholder)->str)
			return ;
		ft_memmove((*strholder)->str, middle, ft_strlen((char *)middle));
	}
	(*strholder)->is_long_set = 1;
}

void	print_result(t_stringholder **strholder)
{
	write(1, (*strholder)->str, ft_strlen((char *)(*strholder)->str));
	write(1, "\n", 1);
	free((*strholder)->str);
	(*strholder)->is_done = 1;
	(*strholder)->size = BUFF_SIZE + 1;
	(*strholder)->str = ft_calloc((*strholder)->size, 1);
	(*strholder)->i_str = 0;
	(*strholder)->is_long_set = 0;
}

void	print_pid()
{
	int			pid;
	char		*pidchar;

	pid = getpid();
	pidchar = ft_itoa(pid);
	write(1, pidchar, ft_strlen(pidchar));
	write(1, "\n", 1);
	free(pidchar);
}
