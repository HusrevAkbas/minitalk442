/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:44:56 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/24 15:52:03 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _GNU_SOURCE
# ifndef BUFF_SIZE
#  define BUFF_SIZE 1000
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
	int				pid_sender;
	unsigned char	*str;
	char			bin[9];
	int				is_long;
	int				is_long_set;
	struct string	*next;
}	t_stringholder;

t_stringholder	*find_last(t_stringholder *head);
t_stringholder	*find_node(t_stringholder *head, int pid_src);
int				ft_atoi_base(char *nbr, char *base);
void			exit_p(int code);
t_stringholder	*init_string(int pid);

void	printlist(t_stringholder *head);
#endif