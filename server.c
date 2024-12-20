/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/20 15:16:01 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*string;

void	print(int signum)
{
	signum = 0;
	while (string->bin[signum])
	{
		if (signum % 8 == 0)
			ft_printf("\n");
		ft_printf("%c", string->bin[signum]);
		signum++;
	}
	
	ft_printf("%s\n", string->bin);
}

void	handler(int signum)
{
	signum = 1;
	string->bin[string->i_bin] = '1';
	string->i_bin++;
	if (string->i_bin == 8)
	{
		string->i_bin = 0;
		print(0);
	}
}

void	handler2(int signum)
{
	signum = 0;
	string->bin[string->i_bin] = '0';
	string->i_bin++;
	if (string->i_bin == 8)
	{
		string->i_bin = 0;
		print(0);
	}
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
	string->str = ft_calloc(1, 82);
	if (!string->str)
	{
		free(string);
		return (EXIT_SUCCESS);
	}
	ft_bzero(string->bin, 9);
	string->i_str = 0;
	string->i_bin = 0;
	string->is_long = 0;
	string->is_long_set = 0;

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
	sigaction(SIGTSTP, &sa_kill, NULL);
	
	while (1)
	{
		pause();
	}
	exit_p(1);
	return (0);
}
