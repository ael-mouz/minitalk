/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:59:33 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/12/29 23:38:59 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "msg received\n", 14);
}

void	ft_send_bits(pid_t k, unsigned char num)
{
	int	i;
	int	c;

	c = 0b10000000;
	i = 0;
	while (i < 8)
	{
		if ((num & c >> i) == 0)
			kill(k, SIGUSR2);
		else
			kill(k, SIGUSR1);
		usleep(700);
		signal(SIGUSR1, ft_handler);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	i;
	size_t	j;

	if (ac == 1 || ac > 3 || ft_atoi(av[1]) <= 0 || av[2] == 0)
		return (0);
	i = ft_atoi(av[1]);
	j = -1;
	while (++j < ft_strlen(av[2]))
		ft_send_bits(i, av[2][j]);
	ft_send_bits(i, 0);
	return (0);
}
