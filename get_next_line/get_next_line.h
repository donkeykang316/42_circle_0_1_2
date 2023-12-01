/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:48:00 by kaan              #+#    #+#             */
/*   Updated: 2023/12/01 17:31:22 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_putstr(char *s);
char	*get_next_line(int fd);

#endif