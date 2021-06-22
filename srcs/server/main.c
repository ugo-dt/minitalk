/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:59:41 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/22 16:22:21 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
