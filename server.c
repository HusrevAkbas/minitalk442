/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/19 14:52:46 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*string;

void	handler(int signum)
{
	int	i;

	signum = 1;
	i = 0;
	i = ft_strlen(string->str);
	string->str[i] = '1';
}

void	handler2(int signum)
{
	int	i;

	signum = 0;
	i = 0;
	i = ft_strlen(string->str);
	string->str[i] = '0';
}

void	print(int signum)
{
	signum = 1;
	ft_printf("%s\n", string->str);
}

void	exit_p(int signum)
{
	signum = 0;
	free(string->str);
	free(string);
	exit(0);
}

int main(void)
{
	int			pid;
	char		*pidchar;
	t_sigaction	sa_usr1;
	t_sigaction	sa_usr2;
	t_sigaction	sa_print;
	t_sigaction	sa_kill;
	sigset_t	set;
	string = malloc(sizeof(t_stringholder));
	if (!string)
		return (0);
	string->str = malloc(1001);
	if (!string->str)
	{
		free(string);
		return (0);
	}
	ft_bzero(string->str, 1001);
	string->i = 1;
	string->is_long = 0;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	pid = getpid();
	pidchar = ft_itoa(pid);
	write(1, pidchar, ft_strlen(pidchar));
	write(1, "\n", 1);
	free(pidchar);
	sa_usr1.sa_flags = SA_RESTART;
	sa_usr1.sa_handler = &handler;
	sa_usr1.sa_mask = set;
	sigaction(SIGUSR1, &sa_usr1, NULL);
	
	sa_usr2.sa_flags = SA_RESTART;
	sa_usr2.sa_handler = &handler2;
	sa_usr2.sa_mask = set;
	sigaction(SIGUSR2, &sa_usr2, NULL);
	
	sa_print.sa_flags = SA_RESTART;
	sa_print.sa_handler = &print;
	sa_print.sa_mask = set;
	sigaction(SIGXFSZ, &sa_print, NULL);
	
	sa_kill.sa_flags = SA_RESTART;
	sa_kill.sa_handler = &exit_p;
	sa_kill.sa_mask = set;
	sigaction(SIGTERM, &sa_kill, NULL);
	
	while (1)
	{
		pause();
	}
	exit_p(1);
	return (0);
}
