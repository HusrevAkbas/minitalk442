/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:44:56 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/14 18:52:55 by huakbas          ###   ########.fr       */
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
# include <stdlib.h>
# include <sys/wait.h>

typedef struct sigaction	t_sigaction;

int		ft_atoi_base(char *nbr, char *base);
void	print_pid(void);
unsigned char	*set_str(unsigned char *str, char *bin, int *bits, int *pid, int *i);
void	set_sa(t_sigaction *sa1, sigset_t *set);

#endif