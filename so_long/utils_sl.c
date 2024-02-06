/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:24:40 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 16:38:55 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map **lst)
{
	t_map	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->line);
		free(*lst);
		*lst = tmp;
	}
}

void	open_display(t_data *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map_width * 64,
			game->map_height * 64,
			"EGG COLLOCTOR");
	display_enter(game);
}

void	free_tile(t_data *game, t_tile *tile)
{
	if (tile->img)
		mlx_destroy_image(game->mlx_ptr, tile->img);
	free(tile);
}

void	cleanup_resources(t_data *game)
{
	free_tile(game, game->enter);
	free_tile(game, game->water);
	free_tile(game, game->dirt);
	free_tile(game, game->egg);
	free_tile(game, game->cow);
	free_tile(game, game->goal);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game->filename);
	free(game);
}

int	close_display(t_data *game)
{
	if (game->enter && !game->map)
		cleanup_resources(game);
	else
	{
		while ((*game->map)->prev)
			*game->map = (*game->map)->prev;
		ft_free_map(game->map);
		cleanup_resources(game);
	}
	exit(0);
}
