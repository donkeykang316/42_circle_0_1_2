/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/25 12:06:16 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;

	i = 0;
	va_list	args;/*va_list name_of_list*/
	va_start(args, format);/*void va_start(va_list name, first(fixed)_argument)*/

	while (i < ft_strlen(format))
	{
		if (ft_isalnum(format[i]) == 8)
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_arg(args, int);/*type va_arg(va_list name, data_type)*/
	/*vacopy();va_copy(va_copy(dest, src)*/
	va_end(args);/*void va_end(va_list name)*/
	return (0);
}
int	main()
{
	ft_printf("write");
}
