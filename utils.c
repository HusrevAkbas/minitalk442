/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:38 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/25 10:47:21 by huakbas          ###   ########.fr       */
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

t_stringholder	*extend_str(t_stringholder *strholder)
{
	unsigned char	*middle;

	strholder->is_long = ft_atoi_base(strholder->bin, "01") - 48;
	if (strholder->is_long == 1)
	{
		middle = strholder->str;
		strholder->str = ft_calloc(ft_strlen((char *)middle) + BUFF_SIZE, 1);
		if (!strholder->str)
			return (NULL);
		ft_memcpy(strholder->str, middle, ft_strlen((char *)middle));
	}
	strholder->is_long_set = 1;
	return strholder;
}
