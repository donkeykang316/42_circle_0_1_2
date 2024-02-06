/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:50:28 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 16:38:13 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_po_check(t_temp *tmp, char *check)
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

int	exit_check(t_temp *tmp, char *check)
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

int	collect_check(t_temp *tmp, char *check)
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

int	false_item_check(t_temp *tmp, char *check)
{
	tmp->i = 0;
	while (check[tmp->i])
	{
		if (check[tmp->i] == 9
			|| (check[tmp->i] >= 32 && check[tmp->i] <= 47)
			|| (check[tmp->i] >= 50 && check[tmp->i] <= 66)
			|| check[tmp->i] == 68
			|| (check[tmp->i] >= 70 && check[tmp->i] <= 79)
			|| (check[tmp->i] >= 81 && check[tmp->i] <= 126))
			return (0);
		tmp->i++;
	}
	return (1);
}

void	item_check(t_data *game, t_temp *tmp, char *check)
{
	if (start_po_check(tmp, check) == 0
		|| collect_check (tmp, check) == 0
		|| exit_check(tmp, check) == 0
		|| false_item_check(tmp, check) == 0)
	{
		ft_printf("ERROR\nMap wrong items\n");
		free_mapcheck(game, tmp, check);
		exit(0);
	}
	else
		return ;
}
