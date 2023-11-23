/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:49:20 by kaan              #+#    #+#             */
/*   Updated: 2023/11/22 11:23:17 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		cc;
	size_t				i;

	p = s;
	cc = c;
	i = 0;
	while (i < n)
	{
		if (p[i] == cc)
		{
			return ((void *)&p[i]);
		}
		i++;
	}
	return (NULL);
}
