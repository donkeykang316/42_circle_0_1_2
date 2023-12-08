/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:56:54 by kaan              #+#    #+#             */
/*   Updated: 2023/12/08 09:58:00 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stack_line(char *temp, int fd)
{
	char		*buffer;
	ssize_t		b_read;

	b_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(buffer);
	return (temp);
}

static char	*handle_nline(char *temp, int i)
{
	char		*str;

	str = ft_substr(temp, 0, i + 1);
	    if (!str)
            return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	char		*remain;
	int			i;

	temp = stack_line(temp, fd);
	if (!temp)
		return(NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\n')
	{
		line = handle_nline(temp, i);
		remain = ft_substr(temp, i + 1, ft_strlen(temp) + i);
		remain[ft_strlen(temp) + 1] = '\0';
		temp = ft_strdup(remain);
		free (remain);
	}
	else
	{
		line = ft_strdup(temp);
		line[ft_strlen(temp)] = '\0';
		temp = NULL;
	}
	return (line);
}

int main()
{
	const char  *filename = "test";
	int         fd;
	int			i = 10;
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
