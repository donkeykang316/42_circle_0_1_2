/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/29 11:45:09 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specifier(char ch, va_list args)
{
	if (ch == 'c')
		ft_putchar(handle_c(ch, args));
	else if (ch == 's')
		ft_putstr(handle_s(ch, args));
	else if (ch == 'p')
	{
		ft_putstr("0x");
		ft_puthex(handle_p(ch, args));
	}
	else if (ch == 'd' || ch == 'i')
		ft_putnbr(handle_d_i(ch, args));
	else if (ch == 'u')
		ft_putnbr(handle_u(ch, args));
	else if (ch == 'x')
		ft_puthex(handle_lx(ch, args));
	else if (ch == 'X')
		ft_puthex_up(handle_ux(ch, args));
	else
	{
		ft_putchar('%');
		ft_putchar(ch);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, format);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			i++;
			specifier(format[i], args);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}
