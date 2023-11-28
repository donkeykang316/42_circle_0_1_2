/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handle_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/28 18:07:05 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	handle_c(char c, va_list args)
{
	char	var;

	var = va_arg(args, int);
	return (var);
}

char	*handle_s(char c, va_list args)
{
	char	*var;

	var = va_arg(args, char *);
	return (var);
}

long	handle_p(char c, va_list args)
{
	long	var;

	var = va_arg(args, long);
	return (var);
}

int	handle_d_i(char c, va_list args)
{
	char	var;

	var = va_arg(args, int);
	return (var);
}
