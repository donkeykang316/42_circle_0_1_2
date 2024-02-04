/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:50:28 by kaan              #+#    #+#             */
/*   Updated: 2024/02/04 17:51:04 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	start_po_check(t_data *game, t_temp *tmp, char *check)
{
	tmp->i = 0;
	while (check[tmp->i])
	{
		if (check[tmp->i] == 'P')
			break ;
		tmp->i++;
	}
	if (!check[tmp->i])
		return (0);
	tmp->i++;
	while (check[tmp->i])
	{
		if (check[tmp->i] == 'P')
			return (0);
		tmp->i++;
	}
	return (1);
}

int	exit_check(t_data *game, t_temp *tmp, char *check)
{
	tmp->i = 0;
	while (check[tmp->i])
	{
		if (check[tmp->i] == 'E')
			break ;
		tmp->i++;
	}
	if (!check[tmp->i])
		return (0);
	tmp->i++;
	while (check[tmp->i])
	{
		if (check[tmp->i] == 'E')
			return (0);
		tmp->i++;
	}
	return (1);
}

int	collect_check(t_data *game, t_temp *tmp, char *check)
{
	tmp->i = 0;
	while (check[tmp->i])
	{
		if (check[tmp->i] == 'C')
			return (1);
		tmp->i++;
	}
	return (0);
}

void	item_check(t_data *game, t_temp *tmp, char *check)
{
	if (start_po_check(game, tmp, check) == 0
		|| collect_check (game, tmp, check) == 0
		|| exit_check(game, tmp, check) == 0)
	{
		ft_printf("ERROR\nMap wrong items\n");
		free_mapcheck(game, tmp, check);
		exit(0);
	}
	else
		return ;
}
