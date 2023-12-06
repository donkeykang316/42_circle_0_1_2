/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:47:24 by kaan              #+#    #+#             */
/*   Updated: 2023/12/06 17:18:28 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_stack(char *buffer, char *temp, int fd)
{
	ssize_t		byteread;

	byteread = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		buffer[byteread] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	//free (buffer);
	return (temp);
}

static char	*set_line(char *temp)
{
	int		i;
	char	*str;
	char	*ptr;

	i = 0;
	while (temp[i] != '\n')
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = temp[i];
	str[i + 1] = '\0';
	temp = ft_substr(temp, i + 1, ft_strlen(temp) - i);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*temp;
	char			*new_temp;
	char			*line;
	char			*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	temp = ft_stack(buffer, temp, fd);
	//line = ft_strdup(temp);
	//printf("buffer check: %s\n", buffer);
    line = set_line(temp);
	//printf("error check: %s\n", temp);
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
		free (c);
		i--;
	}
	close(fd);
}
