/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:44:56 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/13 12:24:03 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _GNU_SOURCE
# ifndef BUFF_SIZE
#  define BUFF_SIZE 100
# endif //BUFF_SIZE
# include "libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct sigaction	t_sigaction;
typedef struct string
{
	int				i_bin;
	int				i_str;
	int				size;
	int				pid_sender;
	t_list			*str_head;
	t_list			*str_current;
	char			bin[9];
	int				is_done;
}	t_stringholder;

void			extend_str(t_stringholder **strholder);
int				ft_atoi_base(char *nbr, char *base);
t_stringholder	*init_string(int pid);
void			print_pid(void);
void			print_result(t_stringholder **strholder);
void			set_sa(t_sigaction *sa1, sigset_t *set);

#endif