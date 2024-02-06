/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:48:03 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 16:37:34 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_data *game)
{
	t_temp		*tmp;
	char		*check;

	check = NULL;
	tmp = tmp_init(game);
	while (tmp->temp)
	{
		if (tmp->temp)
			check = ft_strjoin_gnl(check, tmp->temp);
		free (tmp->temp);
		tmp->temp = get_next_line(tmp->fd);
	}
	mwidth_check(game, tmp, check);
	rectangle_check(game, tmp, check);
	wall_check(game, tmp, check);
	item_check(game, tmp, check);
	path_validation(game, tmp, check);
	free(check);
	close (tmp->fd);
	free_tmp(tmp);
	ft_printf("Map PASS! Have FUN!\n");
}

void	free_mapcheck(t_data *game, t_temp *tmp, char *check)
{
	free(check);
	free(game->filename);
	close (tmp->fd);
	free_tmp(tmp);
	free(game);
}

void	mwidth_check(t_data *game, t_temp *tmp, char *check)
{
	tmp->i = 0;
	while (check[tmp->i] != 10)
		tmp->i++;
	game->map_width = tmp->i;
}

void	rectangle_check(t_data *game, t_temp *tmp, char *check)
{
	tmp->count = 0;
	tmp->i = 0;
	tmp->y = 0;
	while (check[tmp->y] != 10)
		tmp->y++;
	while (check[tmp->i])
	{
		tmp->x = 0;
		while (check[tmp->i] != 10)
		{
			tmp->x++;
			tmp->i++;
		}
		tmp->count++;
		if (tmp->x != tmp->y)
		{
			ft_printf("ERROR\nMap not retanglar\n");
			free_mapcheck(game, tmp, check);
			exit(0);
		}
		tmp->i++;
	}
	game->map_height = tmp->count;
}

void	wall_check(t_data *game, t_temp *tmp, char *check)
{
	tmp->i = 0;
	tmp->count = 0;
	while (check[tmp->i])
	{
		tmp->x = 0;
		while (check[tmp->i] != 10)
		{
			if (((tmp->x == 0 || tmp->x == game->map_width - 1)
					|| (tmp->count == 0 || tmp->count == game->map_height - 1))
				&& check[tmp->i] != '1')
			{
				ft_printf("ERROR\nMap not sealed\n");
				free_mapcheck(game, tmp, check);
				exit(0);
			}
			tmp->i++;
			tmp->x++;
		}
		tmp->count++;
		tmp->i++;
	}
}
