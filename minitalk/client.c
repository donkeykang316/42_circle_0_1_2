/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:31:24 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 23:14:47 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/printf/inc/ft_printf.h"
#include "libraries/libft/inc/libft.h"
#include <stdlib.h>
#include <signal.h>

void	action()

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_printf("Sent :%d\n", ft_strlen(av[2]));
		ft_printf("Received:");
		signal(SIGUSR1, action);
		signal(SIGUSR2, action);
		mt_kill(ft_atoi(av[1]), av[2]);
		while (1)
			pause();
	}
}
