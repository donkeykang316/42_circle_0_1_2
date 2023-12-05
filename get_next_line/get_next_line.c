/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:47:24 by kaan              #+#    #+#             */
/*   Updated: 2023/12/05 17:23:43 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stack(char *temp, int fd)
{
	char			*buffer;
	ssize_t			byteread;

	byteread = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		//printf("error check: %s\n", buffer);
		buffer[byteread] = '\0';
		//printf("error check: %s\n", buffer);
		temp = ft_strjoin(temp, buffer);
	}
	free (buffer);
	return (temp);
}

char	*free_temp(char *temp)
{
	char	*str;

	temp[0] = '\0';
	temp = NULL;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*temp;
	char			*line;

	//printf("error check: %s\n", temp);
	temp = ft_stack(temp, fd);
	line = ft_strdup(temp);
	temp = free_temp(temp);
	//printf("error check: %s\n", temp);
	return (line);
}

int main()
{
	const char  *filename = "test";
	int         fd;
	int			i = 2;
	char	*c;

	fd = open(filename, O_RDONLY);
	while (i > 0)
	{
		c = get_next_line(fd);
		//printf("%s", c);
		free (c);
		i--;
	}
	close(fd);
}
