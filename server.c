/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:22 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/14 13:37:04 by huakbas          ###   ########.fr       */
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
	static int	bits = 0;
	static int	pid = 0;
	static char	bin[9];
	unsigned char	c;

	(void) data;
	if (!pid)
	{
		pid = info->si_pid;
		bits = 0;
		kill(pid, SIGUSR1);
		return ;
	}
	if (pid != info->si_pid)
		return ;
	if (signum == SIGUSR1)
		bin[bits] = '1';
	else
		bin[bits] = '0';
ft_printf("%c", bin[bits]);
	bits++;
	if (bits == 8)
	{
		bits = 0;
		c = ft_atoi_base(bin, "01");
ft_printf("\n%i\n", ft_atoi_base(bin, "01"));
		write(1, &c, 1);
	}
	kill(pid, SIGUSR1);
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
	sigaction(SIGUSR1, &sa_usr1, NULL);
	sigaction(SIGUSR2, &sa_usr1, NULL);
	while (1)
	{
		sleep(1);
	}
	exit_p(0);
	return (0);
}
