/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:42:16 by kaan              #+#    #+#             */
/*   Updated: 2024/01/31 16:09:29 by kaan             ###   ########.fr       */
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

typedef struct s_map
{
	char			*map;
}	t_map;

typedef struct s_cha
{
	char	*ch;
	char	*f_name;
	void	*img;
	int		x;
	int		y;
}	t_cha;

typedef struct s_data
{
	void		*win_ptr;
	void		*mlx_ptr;
	const char	*filename;
	int			fd;
}	t_data;

void	ft_free(t_data *game);
void	open_display(t_data *game);
int		close_display(t_data *game);
t_map	*display_bg(t_data *game);
int		input_manager(int keypress, t_data *game, t_map *card);
void	move_cow(t_data *game, int keypress);
t_tile	*water_tile(t_data *game);
t_tile	*dirt_tile(t_data *game);
t_cha	*cha_tile(t_data *game);
t_tile	*egg_tile(t_data *game);
t_tile	*goal_tile(t_data *game);

#endif
