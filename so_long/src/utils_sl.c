/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:24:40 by kaan              #+#    #+#             */
/*   Updated: 2024/02/03 11:25:07 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	game->win_ptr = mlx_new_window(game->mlx_ptr, 960, 640, "EGG COLLOCTOR");
	display_enter(game);
}

int	close_display(t_data *game, t_map **map)
{
	if (game->enter && !(*map))
	{
		if (game->enter->img)
		{
			mlx_destroy_image(game->mlx_ptr, game->enter->img);
			free(game->enter->f_name);
			free(game->enter);
			free(game->filename);
		}
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
		free(game);
		exit (0);
	}
	else
	{
		while ((*map)->prev)
			*map = (*map)->prev;
		ft_free_map(map);
		if (game->enter->img)
		{
			mlx_destroy_image(game->mlx_ptr, game->enter->img);
			free(game->enter->f_name);
			free(game->enter);
		}
		if (game->water->img)
		{
			mlx_destroy_image(game->mlx_ptr, game->water->img);
			free(game->water->f_name);
			free(game->water);
		}
		if (game->dirt->img)
		{
			mlx_destroy_image(game->mlx_ptr, game->dirt->img);
			free(game->dirt->f_name);
			free(game->dirt);
		}
		if (game->egg->img)
		{
			mlx_destroy_image(game->mlx_ptr, game->egg->img);
			free(game->egg->f_name);
			free(game->egg);
		}
		if (game->cow->img)
		{
			mlx_destroy_image(game->mlx_ptr, game->cow->img);
			free(game->cow->f_name);
			free(game->cow);
		}
		if (game->goal->img)
		{
			mlx_destroy_image(game->mlx_ptr, game->goal->img);
			free(game->goal->f_name);
			free(game->goal);
		}
		free(game->filename);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
		free(game);
		exit (0);
	}
}
