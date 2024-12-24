/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:38 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/24 14:32:14 by huakbas          ###   ########.fr       */
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
	return (string);
}

t_stringholder	*find_node(t_stringholder *head, int pid_src)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->pid_sender == pid_src)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_stringholder	*find_last(t_stringholder *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	printlist(t_stringholder *head)
{
	while (head)
	{
		ft_printf("pid: %i\n", head->pid_sender);
		head = head->next;
	}
}
