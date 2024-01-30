/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:42:16 by kaan              #+#    #+#             */
/*   Updated: 2024/01/30 17:07:11 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../supp/printf/inc/ft_printf.h"
# include "../supp/get_next_line/inc/get_next_line.h"
# include "../supp/libft/inc/libft.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <string.h>

typedef struct s_tile
{
	char	*f_name;
	void	*img;
	int		height;
	int		width;
}	t_tile;

typedef struct s_data
{
	void		*win_ptr;
	void		*mlx_ptr;
	const char	*filename;
	t_tile		*map;
}	t_data;

#endif
