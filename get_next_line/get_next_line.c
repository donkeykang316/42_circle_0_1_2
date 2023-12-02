/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:47:24 by kaan              #+#    #+#             */
/*   Updated: 2023/12/02 18:39:17 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buffer[BUFFER_SIZE + 1];
	char		*newline;
	ssize_t		byteread;
	char		*temp;

	remainder = NULL;
	if (BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	byteread = read(fd, buffer, BUFFER_SIZE);
	if (byteread < 0)
	{
		return (NULL);
	}
	else
	{
			newline = ft_strdup(ft_strchr(buffer, '\n'));
	}
	return (newline);
}

int main()
{
	const char  *filename = "test";
	int         fd;

    fd = open(filename, O_RDONLY);
	printf("%s\n", get_next_line(fd));
	//printf("\n\n");
	//buffer = get_next_line(fd);
	close(fd);
}
