/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/24 16:53:54 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*list;

void	exit_p(int code)
{
	if (list)
	{
		if (list->str)
			free(list->str);
		free(list);
	}
	ft_printf("Exit code: %i\n", code);
	exit(code);
}

void	set_string(t_stringholder *node)
{
	if (ft_atoi_base(node->bin, "01") == 0)
	{
		write(1, node->str, ft_strlen((char *)node->str));
		write(1, "\n", 1);
		node->is_done = 1;
		ft_bzero(node->str, BUFF_SIZE + 1);
		node->i_str = 0;
		usleep(5000);
		return ;
	}
	node->str[node->i_str] = ft_atoi_base(node->bin, "01");
	node->i_str++;
}

void	handler(int signum, siginfo_t *info, void *data)
{
	t_stringholder	*node;
	t_stringholder	*last;

	if (!list)
		list = init_string(info->si_pid);
	node = find_node(list, info->si_pid);
	if (!node)
	{
		node = init_string(info->si_pid);
		if (!node)
			exit_p(0);
		last = find_last(list);
		last->next = node;
	}
	(void) data;
	(void) signum;
	node->bin[node->i_bin] = '1';
	node->i_bin++;
	if (node->i_bin == 8)
	{
		node->i_bin = 0;
		set_string(node);
	}
}

void	handler2(int signum, siginfo_t *info, void *data)
{
	t_stringholder	*node;
	t_stringholder	*last;

	if (!list)
	{
		list = init_string(info->si_pid);
		if (!list)
			exit_p(0);
	}
	node = find_node(list, info->si_pid);
	if (!node)
	{
		node = init_string(info->si_pid);
		if (!node)
			exit_p(0);
		last = find_last(list);
		last->next = node;
	}
	(void) data;
	(void) signum;
	node->bin[node->i_bin] = '0';
	node->i_bin++;
	if (node->i_bin == 8)
	{
		node->i_bin = 0;
		set_string(node);
	}
}

int main(void)
{
	int			pid;
	char		*pidchar;
	t_sigaction	sa_usr1;
	t_sigaction	sa_usr2;
	sigset_t	set;

	list = NULL;

	sigemptyset(&set);	//USE SIGSET TO MASK SIGNALS
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);

	pid = getpid();	//PRINT PROCESS ID
	pidchar = ft_itoa(pid);
	write(1, pidchar, ft_strlen(pidchar));
	write(1, "\n", 1);
	free(pidchar);

	sa_usr1.sa_flags = SA_SIGINFO;	//SIGACTION HANDELS USR1
	//sa_usr1.sa_flags = SA_RESTART;
	//sa_usr1.sa_mask = set;
	sa_usr1.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa_usr1, NULL) == -1)
		exit_p(3);
	
	sa_usr2.sa_flags = SA_SIGINFO;	//SIGACTION HANDELS USR1
	//sa_usr2.sa_flags = SA_RESTART;
	//sa_usr2.sa_mask = set;
	sa_usr2.sa_sigaction = &handler2;
	if (sigaction(SIGUSR2, &sa_usr2, NULL))
		exit_p(3);

	while (1)	//WAIT FOR SIGNALS
	{
		pause();
		//send_feedback(list);
	}
	exit_p(1);
	return (0);
}
