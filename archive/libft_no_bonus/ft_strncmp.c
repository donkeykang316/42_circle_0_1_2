/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:37:09 by kaan              #+#    #+#             */
/*   Updated: 2023/11/22 11:05:58 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i] == 0)
		{
			i++;
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
