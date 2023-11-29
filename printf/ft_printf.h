/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:15:59 by someng            #+#    #+#             */
/*   Updated: 2023/11/29 19:58:58 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_puthex(long n);
int	ft_puthex_up(long n);
int	ft_strlen(const char *s);
int	nbr_len(int nbr);
int	hex_len(long nbr);
int	address_hex_len(long nbr);
int	handle_c(char c, va_list args);
int	handle_s(char c, va_list args);
int	handle_p(char c, va_list args);
int	handle_d_i(char c, va_list args);
int	handle_u(char c, va_list args);
int	handle_lx(char c, va_list args);
int	handle_ux(char c, va_list args);
int	specifier(char ch, va_list args);
int	ft_printf(const char *format, ...);

#endif
