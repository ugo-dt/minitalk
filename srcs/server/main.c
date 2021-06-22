/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:59:41 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/22 21:57:06 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 *	Example: message <a>
 *
 *	SIGUSR1 = 30, 00011110 in binary
 *	SIGUSR2 = 31, 00011111 in binary
 * 
 *	a: 01100001 in binary
 *	
 *	unsigned char c is set to 00000000
 *	
 *	00011110 & 1 = 0
 *	00011111 & 1 = 1
 *	Basic bitwise shifting to the left until we reach 8 bits (for one character)
*/

void	signal_handler(int sig)
{
	static t_msg	msg;

	msg.c += ((sig & 1) << msg.size);
	msg.size++;
	if (msg.size == 7)
	{
		ft_putchar_fd(msg.c, 1);
		if (!msg.c)
			ft_putchar_fd('\n', 1);
		msg.c = 0;
		msg.size = 0;
	}
}

int	main(void)
{
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	write(1, "\n", STDOUT_FILENO);
	while (1)
	{
		signal(SIGUSR2, signal_handler);
		signal(SIGUSR1, signal_handler);
		pause();
	}
	return (EXIT_SUCCESS);
}
