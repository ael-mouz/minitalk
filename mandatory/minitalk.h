/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:56:25 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/12/29 23:57:34 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*------------------ft_server-----------------------------*/
void	ft_signal_handler(int sig, siginfo_t *info, void *uap);
/*------------------ft_client-----------------------------*/
void	ft_send_bits(pid_t k, unsigned char num);
/*------------------ft_utils-----------------------------*/
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_put_nbr(int n);
int		ft_atoi(char *str);

#endif