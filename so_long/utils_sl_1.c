/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:39:25 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 16:38:38 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tmp(t_temp *tmp)
{
	free(tmp->temp);
	free(tmp);
}

t_temp	*tmp_init(t_data *game)
{
	t_temp	*tmp;

	tmp = malloc(sizeof(t_temp));
	if (!tmp)
		exit(0);
	tmp->i = 0;
	tmp->temp = NULL;
	tmp->fd = open(game->filename, O_RDONLY);
	if (tmp->fd < 0 || read(tmp->fd, 0, 0) < 0)
	{
		ft_printf("ERROR\nfile dons't exist\n");
		close (tmp->fd);
		free(game->filename);
		free(game);
		free(tmp);
		exit(0);
	}
	tmp->temp = get_next_line(tmp->fd);
	if (!tmp->temp)
	{
		free(tmp);
		exit(0);
	}
	return (tmp);
}

t_map	*map_list(t_data *game, t_map *m_line)
{
	t_temp	*tmp;

	tmp = tmp_init(game);
	while (tmp->temp)
	{
		if (tmp->temp)
		{
			tmp->new = ft_lstnew_doub(tmp->temp);
			tmp->new->index = tmp->i;
			tmp->new->x = -1;
			ft_lstadd_back_doub(&m_line, tmp->new);
			tmp->i++;
		}
		free (tmp->temp);
		tmp->temp = get_next_line(tmp->fd);
	}
	close (tmp->fd);
	free_tmp(tmp);
	return (m_line);
}

void	display_enter(t_data *game)
{
	game->enter = enter_tile(game);
	game->enter->width = 350;
	game->enter->height = 192;
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr,
		game->enter->img,
		game->enter->width,
		game->enter->height);
}

void	tile_value_init(t_tile *tile)
{
	tile->width = 0;
	tile->height = 0;
}
