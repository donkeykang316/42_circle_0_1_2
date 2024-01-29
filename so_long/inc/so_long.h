/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:42:16 by kaan              #+#    #+#             */
/*   Updated: 2024/01/29 17:11:41 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../printf/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <string.h>

typedef struct s_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	char	*f_name;
	int		height;
	int		width;
}	t_data;

typedef struct s_map
{
	int		height;
	int		width;
	void	*img;
}	t_map;

#endif
