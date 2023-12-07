/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:56:54 by kaan              #+#    #+#             */
/*   Updated: 2023/12/07 08:55:12 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	char		*line;
	ssize_t		b_read;

	char		*str;
	char		*remain;
	int			i;

	b_read = 0;
	i = 0;
	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((b_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[b_read] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
			break;
	}
	free(buffer);
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		i++;
	}
	if (temp[i] == '\n')
	{
		str = ft_substr(temp, 0, i + 1);
		remain = ft_substr(temp, i + 1, ft_strlen(temp) + 1);
		remain[ft_strlen(temp) + 1] = '\0';
		temp = ft_strdup(remain);
		line = ft_strdup(str);
	}
	else
		line = ft_strdup(temp);
	return (line);
}

int main()
{
	const char  *filename = "test";
	int         fd;
	int			i = 6;
	char		*c;

	fd = open(filename, O_RDONLY);
	while (i > 0)
	{
		c = get_next_line(fd);
		printf("%s", c);
		i--;
	}
	free (c);
	close(fd);
}
