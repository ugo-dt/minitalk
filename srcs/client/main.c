/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:59:41 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/22 16:01:24 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(pid_t pid, const char *s, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((s[i] >> shift) & 1)
			{
				if ((kill(pid, SIGUSR2)) == -1)
					error("Error\nCould not find any server with this PID\n");
			}
			else if ((kill(pid, SIGUSR1)) == -1)
				error("Error\nCould not find any server with this PID\n");
			shift++;
			usleep(100);
		}
		i++;
	}
}

void	success(int sig)
{
	(void)sig;
	write(1, "Message sent successfully\n", 26);
}

int	main(int argc, const char **argv)
{
	pid_t		serv_pid;

	if (argc < 3 || argc > 3 || !argv || !str_isdigit(argv[1]))
		error("Error\nUsage: ./client <server PID> <string>\n");
	serv_pid = ft_atol(argv[1]);
	if (serv_pid > INT32_MAX || serv_pid <= 0)
		error("Error\nPlease make sure PID is valid\n");
	signal(SIGUSR1, success);
	send_char(serv_pid, argv[2], ft_strlen(argv[2]));
	return (EXIT_SUCCESS);
}
