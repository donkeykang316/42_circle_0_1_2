/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:42:16 by kaan              #+#    #+#             */
/*   Updated: 2024/02/05 18:04:34 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/printf/inc/ft_printf.h"
# include "../libs/get_next_line/inc/get_next_line.h"
# include "../libs/libft/inc/libft.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>

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
	int				j;
	int				c;
	int				x;
	int				y;
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
	int				map_width;
	int				map_height;
	struct s_tile	*enter;
	struct s_tile	*water;
	struct s_tile	*dirt;
	struct s_tile	*goal;
	struct s_tile	*cow;
	struct s_tile	*egg;
	struct s_map	**map;
}	t_data;

t_map	*ft_lstlast_doub(t_map *lst);
t_map	*ft_lstnew_doub(char *content);
void	ft_lstadd_back_doub(t_map **lst, t_map *new);
int		ft_lstsize_doub(t_map *lst);
void	ft_free_map(t_map **map);
void	open_display(t_data *game);
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
int		close_display(t_data *game);
void	map_check(t_data *game);
void	free_mapcheck(t_data *game, t_temp *tmp, char *check);
void	mwidth_check(t_data *game, t_temp *tmp, char *check);
void	rectangle_check(t_data *game, t_temp *tmp, char *check);
void	wall_check(t_data *game, t_temp *tmp, char *check);
int		start_po_check(t_temp *tmp, char *check);
int		exit_check(t_temp *tmp, char *check);
int		collect_check(t_temp *tmp, char *check);
void	item_check(t_data *game, t_temp *tmp, char *check);
int		false_item_check(t_temp *tmp, char *check);
void	find_p(t_temp *tmp, char *check);
int		flood_fill_c(t_data	*game, char *check, int p_po);
int		flood_fill_e(t_data	*game, char *check, int p_po);
int		find_c(t_temp *tmp, char *check);
int		c_count(char *check);
int		flood_multiple_c(t_data *game, t_temp *tmp, char *check);
void	path_validation(t_data *game, t_temp *tmp, char *check);
void	map_filename_check(t_data *game);

#endif
