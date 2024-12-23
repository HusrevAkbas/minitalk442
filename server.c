/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/23 14:11:54 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*string;

void	exit_p(int signum)
{
	signum = 0;
	free(string->str);
	free(string);
	exit(0);
}

void	print()
{
	unsigned char	*middle;

	if (string->is_long_set == 0)
	{
		if (string->is_long)
		{
			middle = string->str;
			string->str = ft_calloc(ft_strlen((char *)string->str) + BUFF_SIZE, sizeof(char));
			if (!string->str)
			{
				free(middle);
				exit_p(0);
			}
			ft_memcpy(string->str, middle, ft_strlen((char *)middle));
			free(middle);
		}
		string->is_long = ft_atoi_base(string->bin, "01") - 48;
		ft_printf("long: %i\n", string->is_long);
		string->is_long_set = 1;
	}
	else if (ft_atoi_base(string->bin, "01") == 0)
	{
		string->str[string->i_str] = '\n';
		ft_printf("%s", string->str);
		string->i_str = 0;
		ft_bzero(string->str, BUFF_SIZE + 1);
	}
	else
	{
		string->str[string->i_str] = ft_atoi_base(string->bin, "01");
		string->i_str++;
	}
}

void	handler(int signum)
{
	signum = 1;
	string->bin[string->i_bin] = '1';
	string->i_bin++;
	if (string->i_bin == 8)
	{
		string->i_bin = 0;
		print();
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
		print();
	}
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
	string->str = ft_calloc(1, 1602);
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
