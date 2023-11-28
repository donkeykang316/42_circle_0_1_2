/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handle_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/28 18:28:36 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	handle_u(char c, va_list args)
{
	unsigned int	var;

	var = va_arg(args, unsigned int);
	return (var);
}

/*void	handle_lx(char c, va_list args)
{
	char	var;

	var = va_arg(args, int);
}

void	handle_ux(char c, va_list args)
{
	char	var;

	var = va_arg(args, int);
}*/
