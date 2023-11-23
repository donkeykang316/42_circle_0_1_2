/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/23 17:03:39 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;/*va_list name_of_list*/
	
	va_start(args, format);/*void va_start(va_list name, first(fixed)_argument)*/
	va_arg(args, );/*type va_arg(va_list name, data_type)*/
	vacopy();/*va_copy(va_copy(dest, src)*/
	va_end();/*void va_end(va_list name)*/

}
