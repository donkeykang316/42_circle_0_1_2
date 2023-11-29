/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:49:27 by someng            #+#    #+#             */
/*   Updated: 2023/11/29 15:50:32 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr(n);
	}
	else if (n > 16)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	else
	{
		if (n < 10)
		{
			n = n + 48;
			ft_putchar(n);
		}
		else
		{
			n = n + 97 - 10;
			ft_putchar(n);
		}
	}
}

void	ft_puthex_up(long n)
{
	if (n > 16)
	{
		ft_puthex_up(n / 16);
		ft_puthex_up(n % 16);
	}
	else
	{
		if (n < 10)
		{
			n = n + 48;
			ft_putchar(n);
		}
		else
		{
			n = n + 87 - 32;
			ft_putchar(n);
		}
	}
}
