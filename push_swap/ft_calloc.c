/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:41:27 by someng            #+#    #+#             */
/*   Updated: 2024/01/02 16:14:58 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = malloc (nmemb * size);
	if (!p)
		return (NULL);
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
