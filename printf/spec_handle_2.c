/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handle_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/29 11:46:05 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	handle_u(char c, va_list args)
{
	unsigned int	var;

	(void)c;
	var = va_arg(args, unsigned int);
	return (var);
}

long	handle_lx(char c, va_list args)
{
	long	var;

	(void)c;
	var = va_arg(args, long);
	return (var);
}

long	handle_ux(char c, va_list args)
{
	long	var;

	(void)c;
	var = va_arg(args, long);
	return (var);
}
