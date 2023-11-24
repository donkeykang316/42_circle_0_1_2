/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:40:36 by kaan              #+#    #+#             */
/*   Updated: 2023/11/24 21:05:40 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	cc;
	char	*r;

	i = 0;
	cc = c;
	r = NULL;
	while (str[i])
	{
		if (str[i] == cc)
		{
			r = ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == c)
		r = ((char *)&str[i]);
	return (r);
}
