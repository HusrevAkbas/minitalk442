/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/09 16:33:37 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*g_strholder;

void	exit_p(int code)
{
	if (g_strholder->str)
		free(g_strholder->str);
	free(g_strholder);
	ft_printf("Exit code: %i\n", code);
	exit(code);
}

void	set_string(t_stringholder *strholder)
{
	if (ft_atoi_base(strholder->bin, "01") == 0)
	{
		if (!ft_strncmp((char *)strholder->str, "exit", 8))
			exit_p(0);
		print_result(&strholder);
		if (!strholder->str)
			exit_p(0);
	}
	else if (strholder->is_long_set == 0)
	{
		strholder->is_long = ft_atoi_base(strholder->bin, "01") - 48;
		if (strholder->is_long == 1)
			extend_str(&strholder);
		if (!strholder->str)
			exit_p(1);
		strholder->is_long_set = 1;
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
	(void) data;
	(void) signum;
	g_strholder->pid_sender = info->si_pid;
	if (signum == SIGUSR1)
		g_strholder->bin[g_strholder->i_bin] = '1';
	else
		g_strholder->bin[g_strholder->i_bin] = '0';
	g_strholder->i_bin++;
	if (g_strholder->i_bin == 8)
	{
		g_strholder->i_bin = 0;
		set_string(g_strholder);
	}
}

int	main(void)
{
	t_sigaction	sa_usr1;
	sigset_t	set;

	g_strholder = init_string(-1);
	if (!g_strholder)
		exit_p(1);
	print_pid();
	set_sa(&sa_usr1, &set);
	sa_usr1.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa_usr1, NULL) == -1)
		exit_p(3);
	if (sigaction(SIGUSR2, &sa_usr1, NULL) == -1)
		exit_p(3);
	while (1)
	{
		pause();
		if (g_strholder->is_done == 1)
		{
			kill(g_strholder->pid_sender, SIGUSR1);
			g_strholder->is_done = 0;
		}
	}
	exit_p(0);
	return (0);
}
