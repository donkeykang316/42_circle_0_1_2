/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:24:40 by kaan              #+#    #+#             */
/*   Updated: 2024/02/02 12:59:12 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free_map(t_map *map)
{
	free(map->line);
	free(map);
}

void	open_display(t_data *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 960, 640, "EGG COLLOCTOR");
	display_enter(game);
}

int	close_display(t_data *game, t_map **map)
{
	if (game->win_ptr != NULL)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		//free(game->win_ptr);
	}
	if (game->mlx_ptr != NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		//free(game->mlx_ptr);
	}
	if (!(*map))
	{
		while ((*map)->prev)
			*map = (*map)->prev;
		while ((*map)->next)
		{
			ft_free_map(*map);
			*map = (*map)->next;
		}
	}
	free(game->filename);
	//free(game);
	exit (1);
}
