/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:44:56 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/25 10:47:07 by huakbas          ###   ########.fr       */
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
t_stringholder	*extend_str(t_stringholder *strholder);
t_stringholder	*init_string(int pid);
void			send_feedback(t_stringholder *list);

#endif