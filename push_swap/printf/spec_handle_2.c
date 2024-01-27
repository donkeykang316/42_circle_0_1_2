/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handle_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:14 by kaan              #+#    #+#             */
/*   Updated: 2023/11/30 19:24:54 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_lx(char c, va_list args)
{
	unsigned int	var;
	int				count;

	count = 0;
	(void)c;
	var = va_arg(args, long);
	ft_puthex(var, &count);
	return (count);
}

int	handle_ux(char c, va_list args)
{
	unsigned int	var;
	int				count;

	count = 0;
	(void)c;
	var = va_arg(args, long);
	ft_puthex_up(var, &count);
	return (count);
}
