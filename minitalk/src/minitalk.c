/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:25 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 17:57:28 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	message(void)
{
	ft_printf("Hi the Kang!\n");
}

int	main(void)
{
	signal(SIGINT, message);
	signal(SIGTERM, message);
}
