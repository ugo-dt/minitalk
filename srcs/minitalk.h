/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:00:04 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/22 14:52:22 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_msg
{
	char	c;
	size_t	size;
}t_msg;

/*
 *	Utils
*/

long	ft_atol(const char *nptr);

void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(const char c, int fd);

int		ft_isdigit(int c);
int		str_isdigit(const char *s);

size_t	ft_strlen(const char *s);

void	error(char *s);

#endif /* !_MINITALK_H */