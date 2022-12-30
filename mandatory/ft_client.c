/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:54:33 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/12/29 23:56:21 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	i;
	size_t	j;

	if (ac == 1 || ac > 3 || ft_atoi(av[1]) <= 0 || av[2] == NULL)
		return (0);
	i = ft_atoi(av[1]);
	j = -1;
	while (++j < ft_strlen(av[2]))
		ft_send_bits(i, av[2][j]);
	ft_send_bits(i, 0);
	return (0);
}
