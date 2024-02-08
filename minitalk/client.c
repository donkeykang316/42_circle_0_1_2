/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:31:24 by kaan              #+#    #+#             */
/*   Updated: 2024/02/08 12:51:24 by kaan             ###   ########.fr       */
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
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (av[1][i] < '0' || av[1][i] > '9')
			{
				ft_printf("Wrong PID!\n");
				return (0);
			}
			i++;
		}
		pid = ft_atoi(av[1]);
		if (pid < 0)
		{
			ft_printf("Wrong PID!\n");
			return (0);
		}
		ft_printf("Client PID [%d]\n", getpid());
		ft_printf("Sending PID to server...\n");
		send_bit(pid, av);
	}
	else
		ft_printf("Wrong input, enter Server PID and then then the message\n");
}
