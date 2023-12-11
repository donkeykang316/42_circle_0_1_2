/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:56:54 by kaan              #+#    #+#             */
/*   Updated: 2023/12/11 18:50:07 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*stack_line(char *temp, char *buffer, int fd)
{
	ssize_t		b_read;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(buffer);
	return (temp);
}

static char	*handle_nline(char *line)
{
	char		*remain;
	ssize_t		i;

	i = 0;
	while (line[i] != '\n' && line[i] != 0)
		i++;
	if (line[i] == 0)
		return (NULL);
	remain = ft_substr(line, i + 1, ft_strlen(line) - i);
	line[i + 1] = '\0';
	return (remain);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (0);
	}
	line = stack_line(temp, buffer, fd);
	if (!line)
	{
		free (line);
		return (NULL);
	}
	else if (line[0] == 0)
		return (NULL);
	temp = handle_nline(line);
	return (line);
}

/*int main()
{
	const char	*filename = "read_error.txt";
	int         fd;
	int			i = 5;
	char		*c;

	fd = open(filename, O_RDONLY);
	while (i > 0)
	{
		c = get_next_line(fd);
		printf("%s", c);
		free(c);
		i--;
	}
	close(fd);
}*/
