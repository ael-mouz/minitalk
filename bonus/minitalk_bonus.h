/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:01:43 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/12/29 23:57:37 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*------------------ft_server_bonus-----------------------------*/
int		check_byte(char buffer, pid_t k, int l);
void	print_byte(unsigned char *buffer, int *l, int *i, int *s);
void	ft_signal_handler(int sig, siginfo_t *info, void *uap);
/*------------------ft_client_bonus-----------------------------*/
void	ft_handler(int signum);
void	ft_send_bits(pid_t k, unsigned char num);
/*------------------ft_utils_bonus-----------------------------*/
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_put_nbr(int n);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(char *str);

#endif