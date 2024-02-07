/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:31:24 by kaan              #+#    #+#             */
/*   Updated: 2024/02/07 17:32:12 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/printf/inc/ft_printf.h"
#include "libraries/libft/inc/libft.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void	sig_handler(int signbr)
{
}

int	main(int ac, char **av)
{
	signal(SIGUSR2, sig_handler);
	ft_printf("Client PID [%d]\n", getpid());
	ft_printf("Sending PID to server...\n");
}
