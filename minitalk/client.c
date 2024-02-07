/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:31:24 by kaan              #+#    #+#             */
/*   Updated: 2024/02/07 22:46:22 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/printf/inc/ft_printf.h"
#include "libraries/libft/inc/libft.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	send_bit(int pid, char **av)
{
	int	i;
	int	x;
	int	message;

	i = 0;
	while (av[2][i])
	{
		message = av[2][i];
		x = 128;
		while (x > 0)
		{
			if (message & x)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			x /= 2;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		ft_printf("Client PID [%d]\n", getpid());
		ft_printf("Sending PID to server...\n");
		send_bit(pid, av);
	}
	else
		ft_printf("Wrong input, enter Server PID and then then the message\n");
}
