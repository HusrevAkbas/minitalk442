/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:44:56 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/30 15:30:04 by huakbas          ###   ########.fr       */
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
//#include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct sigaction	t_sigaction;
typedef struct string
{
	int				i_bin;
	int				i_str;
	int				size;
	int				pid_sender;
	unsigned char	*str;
	char			bin[9];
	int				is_done;
	int				is_long;
	int				is_long_set;
}	t_stringholder;

int				ft_atoi_base(char *nbr, char *base);
void			exit_p(int code);
void			extend_str(t_stringholder **strholder);
t_stringholder	*init_string(int pid);
void			print_pid();
void			print_result(t_stringholder **strholder);
void			send_feedback(t_stringholder *list);
void			set_sa(t_sigaction *sa1, t_sigaction *sa2, sigset_t *set);

#endif