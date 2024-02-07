/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:31:39 by kaan              #+#    #+#             */
/*   Updated: 2024/02/07 22:32:54 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/printf/inc/ft_printf.h"
#include "libraries/libft/inc/libft.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

char	bits_to_char(char bits[])
{
	char	result;
	int		i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result |= (bits[i] - '0') << (7 - i);
		i++;
	}
	return (result);
}

static void	sig_handler(int signbr)
{
	static char	buffer[9];
	static int	i = 0;

	if (signbr == SIGUSR1)
		buffer[i] = '0';
	else
		buffer[i] = '1';
	i++;
	if (i == 8)
	{
		buffer[9] = '\0';
		ft_printf("%c", bits_to_char(buffer));
		i = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_printf("Server PID [%d]\n", getpid());
	while (1)
	{
		sleep(1);
	}
}
