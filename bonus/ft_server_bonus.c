/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:59:53 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/12/30 00:19:01 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	check_byte(char buffer, pid_t k, int l)
{
	static int	s;

	if (buffer == 0)
		kill(k, SIGUSR1);
	if (l == 0)
	{
		if (((buffer >> 4) & 15) == 15)
			s = 4;
		else if (((buffer >> 5) & 7) == 7)
			s = 3;
		else if (((buffer >> 6) & 3) == 3)
			s = 2;
		else if (((buffer >> 7) & 1) == 1 || ((buffer >> 7) & 1) == 0)
			s = 1;
	}
	return (s);
}

void	print_byte(unsigned char *buffer, int *l, int *i, int *s)
{
	int	j;

	j = -1;
	while (++j <= 4)
	{
		if ((*s) == j)
		{
			if ((*l) == j - 1)
			{
				write(1, buffer, j);
				ft_bzero(buffer, 4);
				(*l) = 0;
				(*s) = 0;
				break ;
			}
			else
			{
				(*l)++;
				break ;
			}
		}
	}
	if ((*l) > 3)
		(*l) = 0;
	(*i) = 0;
}

void	ft_signal_handler(int sig, siginfo_t *info, void *ptr)
{
	static unsigned char	buffer[4];
	static pid_t			pid;
	static int				i;
	static int				l;
	static int				s;

	(void)ptr;
	if (pid != info->si_pid)
	{
		i = 0;
		l = 0;
		s = 0;
		ft_bzero(buffer, 4);
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		buffer[l] = (buffer[l] << 1) | 1;
	else if (sig == SIGUSR2)
		buffer[l] = (buffer[l] << 1) | 0;
	if (++i >= 8)
	{
		pid = info->si_pid;
		s = check_byte(buffer[0], pid, l);
		print_byte(&buffer[0], &l, &i, &s);
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
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
}
