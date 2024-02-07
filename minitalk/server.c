/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:31:39 by kaan              #+#    #+#             */
/*   Updated: 2024/02/07 11:32:11 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/printf/inc/ft_printf.h"
#include "libraries/libft/inc/libft.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void	sig_handler(int signbr, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signbr == SIGUSR1)
	{
		ft_printf("\nsignal handler function called %d\n", signbr);
		kill(info->si_pid, SIGUSR2);
		sleep(2);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
	ft_printf("Server PID: [%d]\n", getpid());
	while (1)
		sleep(1);

}
