/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/28 18:27:07 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		ft_putstr(handle_u(ch, args));
	/*else if (ch == 'x')
		ft_putstr(handle_lx(ch, args));
	else if (ch == 'X')
		ft_putstr(handle_ux(ch, args));*/
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
int	main()
{
	char	c = 'c';
	char	b[] = "hello there";
	char	*d = b;
	int		i = 1111;
	int		nb = -2222;

	ft_printf("character:%c\nstring:%s\naddress:%p\nnumber1:%i\nnumber2:%d\n", c, b, d, i, nb);
}
