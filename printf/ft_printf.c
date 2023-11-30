/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/30 19:26:35 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier(char ch, va_list args)
{
	int	count;

	count = 0;
	if (ch == 'c')
		count += handle_c(ch, args);
	else if (ch == 's')
		count += handle_s(ch, args);
	else if (ch == 'p')
		count += handle_p(ch, args);
	else if (ch == 'd' || ch == 'i')
		count += handle_d_i(ch, args);
	else if (ch == 'u')
		count += handle_u(ch, args);
	else if (ch == 'x')
		count += handle_lx(ch, args);
	else if (ch == 'X')
		count += handle_ux(ch, args);
	else
	{
		count += ft_putchar(ch);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			i++;
			j += specifier(format[i], args);
		}
		else
			j += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (j);
}
