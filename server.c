/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/11 15:16:56 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*g_strholder;

void	exit_p(int code)
{
	if (g_strholder->str_head)
		ft_lstclear(&g_strholder->str_head);
	free(g_strholder->str_head);
	free(g_strholder);
	ft_printf("Server closed with code: %i\n", code);
	exit(code);
}

void	set_string(void)
{
	if (!g_strholder || !g_strholder->str_head || !g_strholder->str_current)
		exit_p(1);
	if (ft_atoi_base(g_strholder->bin, "01") == 0)
		g_strholder->is_done = 1;
	else
	{
		g_strholder->str_current->content[g_strholder->i_str]
			= ft_atoi_base(g_strholder->bin, "01");
		g_strholder->i_str++;
	}
	if (g_strholder->i_str == 1000)
		extend_str(&g_strholder);
	if (!g_strholder->str_current)
		exit_p(1);
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
		set_string();
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
			print_result(&g_strholder);
			kill(g_strholder->pid_sender, SIGUSR1);
		}
		if (g_strholder->is_done == 2)
			exit_p(0);
	}
	exit_p(0);
}
