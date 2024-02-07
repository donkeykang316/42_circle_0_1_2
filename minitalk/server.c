/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:31:39 by kaan              #+#    #+#             */
/*   Updated: 2024/02/07 17:27:44 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/printf/inc/ft_printf.h"
#include "libraries/libft/inc/libft.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void	sig_handler(int signbr)
{
	if (signbr == SIGUSR2)
	{
		ft_printf("\nsignal handler function called\n");
	}
}

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	ft_printf("Server PID [%d]\n", getpid());
	while (1)
		sleep(1);
}
