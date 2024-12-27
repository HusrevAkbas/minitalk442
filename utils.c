/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:38 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/27 15:48:36 by huakbas          ###   ########.fr       */
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

void	send_feedback(t_stringholder *list)
{
	if (list->is_done == 1)
	{
		kill(list->pid_sender, SIGUSR1);
		list->is_done = 0;
	}
}

void	extend_str(t_stringholder **strholder)
{
	unsigned char	*middle;

	(*strholder)->is_long = ft_atoi_base((*strholder)->bin, "01") - 48;
	if ((*strholder)->is_long == 1)
	{
		middle = (*strholder)->str;
		(*strholder)->str = ft_calloc(ft_strlen((char *)middle) + BUFF_SIZE, 1);
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
