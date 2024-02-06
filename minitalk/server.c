/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:31:39 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 23:14:00 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/printf/inc/ft_printf.h"
#include "libraries/libft/inc/libft.h"
#include <stdlib.h>
#include <signal.h>

static void	sig_handler(int signbr, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)signbr;
	ft_printf("\nsignal handler function called %d\n", signbr);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: [%d]\n", getpid());
	s_sigaction.sa_flags = SA_RESTART | SA_SIGINFO;
	s_sigaction.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		sleep(1);

}
