/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:38 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/10 16:50:58 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*init_string(int pid_src)
{
	t_stringholder	*string;

	string = malloc(sizeof(t_stringholder));
	if (!string)
		return (NULL);
	string->str_head = malloc(sizeof(t_list));
	if (!string->str_head)
	{
		free(string);
		return (NULL);
	}
	string->str_head->content = ft_calloc(BUFF_SIZE + 1, 1);
	if (!string->str_head->content)
	{
		free(string->str_head);
		free(string);
		return (NULL);
	}
	string->str_head->next = NULL;
	string->str_current = string->str_head;
	ft_bzero(string->bin, 9);
	string->pid_sender = pid_src;
	string->i_bin = 0;
	string->i_str = 0;
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
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		ft_lstclear(&(*strholder)->str_head);
		return ;
	}
	new_node->content = ft_calloc(BUFF_SIZE + 1, 1);
	if (!new_node->content)
	{
		ft_lstclear(&(*strholder)->str_head);
		return ;
	}
	new_node->next = NULL;
	(*strholder)->str_current->next = new_node;
	(*strholder)->str_current = new_node;
	(*strholder)->i_str = 0;
}

void	print_result(t_stringholder **strholder)
{
	t_list	*list;
	t_list	*head;

	if (!strholder || !(*strholder) || !(*strholder)->str_head)
		return ;
	head = (*strholder)->str_head;
	list = head;
	(*strholder)->is_done = 0;
	if (!ft_strncmp((char *)list->content, "exit", 4))
		(*strholder)->is_done = 2;
	while (list)
	{
		(*strholder)->i_str = 0;
		while (list->content[(*strholder)->i_str])
		{
			write(1, &list->content[(*strholder)->i_str], 1);
			(*strholder)->i_str++;
		}
		list = list->next;
	}
	write(1, "\n", 1);
	(*strholder)->i_str = 0;
	ft_lstclear(&(*strholder)->str_head->next);
	ft_bzero((*strholder)->str_head->content, BUFF_SIZE + 1);
	ft_bzero((*strholder)->bin, 9);
	(*strholder)->i_bin = 0;
	(*strholder)->str_current = (*strholder)->str_head;
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
