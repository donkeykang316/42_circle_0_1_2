/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:15:59 by someng            #+#    #+#             */
/*   Updated: 2023/11/28 18:31:28 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
void			ft_puthex(long n);
size_t			ft_strlen(const char *s);
char			handle_c(char c, va_list args);
char			*handle_s(char c, va_list args);
long			handle_p(char c, va_list args);
int				handle_d_i(char c, va_list args);
unsigned int	handle_u(char c, va_list args);
void			handle_lx(char c, va_list args);
void			handle_ux(char c, va_list args);

#endif
