/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:48:03 by kaan              #+#    #+#             */
/*   Updated: 2024/02/04 17:48:52 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	if (tmp->i != 15)
	{
		ft_printf("ERROR\nMap width not valid\n");
		free_mapcheck(game, tmp, check);
		exit(0);
	}
}

void	mheight_check(t_data *game, t_temp *tmp, char *check)
{
	if (tmp->count != 10)
	{
		ft_printf("ERROR\nMap height not valid\n");
		free_mapcheck(game, tmp, check);
		exit(0);
	}
}

void	rectangle_check(t_data *game, t_temp *tmp, char *check)
{
	tmp->count = 0;
	tmp->i = 0;
	while (check[tmp->i])
	{
		tmp->x = 0;
		while (check[tmp->i] != 10)
		{
			tmp->x++;
			tmp->i++;
		}
		tmp->count++;
		if (tmp->x != 15)
		{
			ft_printf("ERROR\nMap not retanglar\n");
			free_mapcheck(game, tmp, check);
			exit(0);
		}
		tmp->i++;
	}
	mheight_check(game, tmp, check);
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
			if (((tmp->x == 0 || tmp->x == 14)
					|| (tmp->count == 0 || tmp->count == 9))
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
