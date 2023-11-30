/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:26:54 by kaan              #+#    #+#             */
/*   Updated: 2023/11/30 19:11:52 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int *count)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr(n, count);
		(*count)++;
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
		(*count)++;
	}
	return (0);
}
