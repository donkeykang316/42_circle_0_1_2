/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:35:58 by kaan              #+#    #+#             */
/*   Updated: 2023/11/21 12:36:56 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	add_i(unsigned int i, char c)
{
	return (i + c);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(ft_strlen(s) + 1);
	while (s[i] != '\0')
	{
		new[i] = f(j, s[i]);
		i++;
		j++;
	}
	return (new);
}
