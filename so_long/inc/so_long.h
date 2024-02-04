/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:42:16 by kaan              #+#    #+#             */
/*   Updated: 2024/02/04 00:44:08 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
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
	char			*f_name;
	void			*img;
	int				height;
	int				width;
}	t_tile;

typedef struct s_map
{
	char			*line;
	int				index;
	int				x;
	struct s_map	*prev;
	struct s_map	*next;
}	t_map;

typedef struct s_temp
{
	char			*temp;
	int				fd;
	int				i;
	int				x;
	int				count;
	struct s_map	*new;
}	t_temp;

typedef struct s_data
{
	void			*win_ptr;
	void			*mlx_ptr;
	char			*filename;
	int				x;
	int				step;
	struct s_tile	*enter;
	struct s_tile	*water;
	struct s_tile	*dirt;
	struct s_tile	*goal;
	struct s_tile	*cow;
	struct s_tile	*egg;
}	t_data;

t_map	*ft_lstlast_doub(t_map *lst);
t_map	*ft_lstnew_doub(char *content);
void	ft_lstadd_back_doub(t_map **lst, t_map *new);
int		ft_lstsize_doub(t_map *lst);
void	ft_free_map(t_map **map);
void	open_display(t_data *game);
int		close_display(t_data *game, t_map **map);
void	display_bg(t_data *game, t_map *m_line);
t_temp	*tmp_init(t_data *game);
t_map	*map_init(t_data *game);
t_map	*map_list(t_data *game, t_map *m_line);
int		input_manager(int keypress, t_data *game, t_map **m_l);
int		win_check(t_map *card);
t_map	*find_cow(t_map **cow);
void	move_cow_a(t_data *game, t_map **m_line);
void	move_cow_d(t_data *game, t_map **m_line);
void	move_cow_w(t_data *game, t_map **cow);
void	move_cow_s(t_data *game, t_map **cow);
t_tile	*water_tile(t_data *game);
t_tile	*dirt_tile(t_data *game);
t_tile	*cow_tile(t_data *game);
t_tile	*egg_tile(t_data *game);
t_tile	*goal_tile(t_data *game);
t_tile	*enter_tile(t_data *game);
void	display_enter(t_data *game);
void	game_start(t_data *game, t_map *m_line);
void	free_tmp(t_temp *tmp);
void	tile_value_init(t_tile *tile);
void	tile_put_img(t_data *game, t_map *m_line, t_tile *tile, int coor);
void	gametile_init(t_data *game);
void	free_tile(t_data *game, t_tile *tile);
void	cleanup_resources(t_data *game);
int		close_display(t_data *game, t_map **map);
int		map_check(t_data *game);

#endif
