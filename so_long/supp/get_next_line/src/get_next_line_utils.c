/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:56:41 by kaan              #+#    #+#             */
/*   Updated: 2024/01/30 13:13:27 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = c;
	while (s[i] != cc && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == cc)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

char	*ft_strdup_gnl(char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(ft_strlen_gnl(s) + 1);
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
	if (len > ft_strlen_gnl(s + start))
		len = ft_strlen_gnl(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	new = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}
