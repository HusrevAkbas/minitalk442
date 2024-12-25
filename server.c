/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/25 10:49:29 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*strholder;

void	exit_p(int code)
{
	if (strholder)
	{
		free(strholder->str);
		free(strholder);
	}
	ft_printf("Exit code: %i\n", code);
	exit(code);
}

void	set_string(t_stringholder *strholder)
{
	unsigned char	*middle;

	if (strholder->is_long_set == 0 && ft_atoi_base(strholder->bin, "01") != 0)
	{
		strholder->is_long = ft_atoi_base(strholder->bin, "01") - 48;
		if (strholder->is_long == 1)
		{
			strholder->size += BUFF_SIZE;
			middle = strholder->str;
			strholder->str = ft_calloc(strholder->size, 1);
			if (!strholder->str)
				exit_p(EXIT_FAILURE);
			ft_memcpy(strholder->str, middle, ft_strlen((char *)middle));
		}
		strholder->is_long_set = 1;
	}
	else if (ft_atoi_base(strholder->bin, "01") == 0)
	{
		if (!ft_strncmp((char *)strholder->str, "sudoexit", 8))
			exit_p(0);
		write(1, strholder->str, ft_strlen((char *)strholder->str));
		write(1, "\n", 1);
		strholder->is_done = 1;
		free(strholder->str);
		strholder->size = BUFF_SIZE + 1;
		strholder->str = ft_calloc(strholder->size, 1);
		strholder->i_str = 0;
		strholder->is_long_set = 0;
		return ;
	}
	else
	{
		strholder->str[strholder->i_str] = ft_atoi_base(strholder->bin, "01");
		strholder->i_str++;
		if (strholder->i_str % BUFF_SIZE == 0)
			strholder->is_long_set = 0;
	}
}

void	handler(int signum, siginfo_t *info, void *data)
{
	strholder->pid_sender = info->si_pid;
	(void) data;
	(void) signum;
	strholder->bin[strholder->i_bin] = '1';
	strholder->i_bin++;
	if (strholder->i_bin == 8)
	{
		strholder->i_bin = 0;
		set_string(strholder);
	}
}

void	handler2(int signum, siginfo_t *info, void *data)
{
	(void) data;
	(void) signum;
	strholder->pid_sender = info->si_pid;
	strholder->bin[strholder->i_bin] = '0';
	strholder->i_bin++;
	if (strholder->i_bin == 8)
	{
		strholder->i_bin = 0;
		set_string(strholder);
	}
}

int main(void)
{
	int			pid;
	char		*pidchar;
	t_sigaction	sa_usr1;
	t_sigaction	sa_usr2;
	sigset_t	set;

	strholder = init_string(-1);
	if (!strholder)
		exit_p(1);

	sigemptyset(&set);	//USE SIGSET TO MASK SIGNALS
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);

	pid = getpid();	//PRINT PROCESS ID
	pidchar = ft_itoa(pid);
	write(1, pidchar, ft_strlen(pidchar));
	write(1, "\n", 1);
	free(pidchar);

	sa_usr1.sa_flags = SA_SIGINFO;	//SIGACTION HANDELS USR1
	sa_usr1.sa_mask = set;
	sa_usr1.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa_usr1, NULL) == -1)
		exit_p(3);
	
	sa_usr2.sa_flags = SA_SIGINFO;	//SIGACTION HANDELS USR1
	sa_usr2.sa_mask = set;
	sa_usr2.sa_sigaction = &handler2;
	if (sigaction(SIGUSR2, &sa_usr2, NULL))
		exit_p(3);

	while (1)	//WAIT FOR SIGNALS
	{
		pause();
		send_feedback(strholder);
	}
	exit_p(0);
	return (0);
}
