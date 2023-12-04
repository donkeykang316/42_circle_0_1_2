/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:47:24 by kaan              #+#    #+#             */
/*   Updated: 2023/12/04 17:50:38 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	stack_line(char *buffer, int fd)
{
	ssize_t			byteread;	

	byteread = 0;
	while (*buffer)
	{
		if (*buffer != '\n')
			byteread += read(fd, buffer, BUFFER_SIZE);
		printf("%zu\n", byteread);
		buffer++;
	}
	return (byteread);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*temp;
	char			*line;
	ssize_t			byteread;

	temp = NULL;
	buffer = malloc(byteread + 1);
	byteread = stack_line(buffer, fd);
	line = malloc(byteread + 1);
	temp = ft_strdup(buffer);
	return (temp);
}

int main()
{
	const char  *filename = "test";
	int         fd;
	int			i = 3;

	fd = open(filename, O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
