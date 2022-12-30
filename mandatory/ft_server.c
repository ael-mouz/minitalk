/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:12:04 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/12/29 23:56:08 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int sig, siginfo_t *info, void *ptr)
{
	static int		i;
	static char		ch;
	static pid_t	pid;

	(void)ptr;
	if (pid != info->si_pid)
	{
		i = 0;
		ch = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		ch = (ch << 1) | 1;
	else if (sig == SIGUSR2)
		ch = (ch << 1) | 0;
	if (++i >= 8)
	{
		ft_putchar(ch);
		ch = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				i;

	i = getpid();
	ft_put_nbr(i);
	ft_putchar('\n');
	act.sa_sigaction = ft_signal_handler;
	act.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
