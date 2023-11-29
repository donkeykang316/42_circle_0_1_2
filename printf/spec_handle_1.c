/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handle_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/29 17:22:59 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(char c, va_list args)
{
	char	var;

	(void)c;
	var = va_arg(args, int);
	ft_putchar(var);
	return (sizeof(char));
}

int	handle_s(char c, va_list args)
{
	char	*var;

	(void)c;
	var = va_arg(args, char *);
	ft_putstr(var);
	return (ft_strlen(var));
}

int	handle_p(char c, va_list args)
{
	long	var;

	(void)c;
	var = va_arg(args, long);
	ft_putstr("0x");
	ft_puthex(var);
	return (address_hex_len(var));
}

int	handle_d_i(char c, va_list args)
{
	int	var;

	(void)c;
	var = va_arg(args, int);
	ft_putnbr(var);
	return (nbr_len(var));
}

int	handle_u(char c, va_list args)
{
	unsigned int	var;

	(void)c;
	var = va_arg(args, unsigned int);
	ft_putnbr(var);
	return (nbr_len(var));
}
