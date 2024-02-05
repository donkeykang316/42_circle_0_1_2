/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:22:20 by kaan              #+#    #+#             */
/*   Updated: 2024/02/05 17:04:03 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	find_p(t_temp *tmp, char *check)
{
	if (tmp->temp)
		free (tmp->temp);
	tmp->temp = NULL;
	tmp->temp = ft_strdup(check);
	tmp->i = 0;
	while (check[tmp->i])
	{
		if (check[tmp->i] == 'P')
			return ;
		tmp->i++;
	}
}

int	flood_fill_e(t_data	*game, char *check, int p_po)
{
	if (p_po < 0 || check[p_po] == '1')
		return (0);
	if (check[p_po] == 'E')
		return (1);
	check[p_po] = '1';
	if (flood_fill_e(game, check, p_po - (game->map_width + 1))
		|| flood_fill_e(game, check, p_po + game->map_width + 1)
		|| flood_fill_e(game, check, p_po - 1)
		|| flood_fill_e(game, check, p_po + 1))
		return (1);
	return (0);
}

int	flood_fill_c(t_data	*game, char *check, int p_po)
{
	if (p_po < 0 || check[p_po] == '1' || check[p_po] == 'E')
		return (0);
	if (check[p_po] == 'P')
		return (1);
	check[p_po] = '1';
	if (flood_fill_c(game, check, p_po - (game->map_width + 1))
		|| flood_fill_c(game, check, p_po + game->map_width + 1)
		|| flood_fill_c(game, check, p_po - 1)
		|| flood_fill_c(game, check, p_po + 1))
		return (1);
	return (0);
}

int	c_count(char *check)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (check[i])
	{
		if (check[i] == 'C')
			x++;
		i++;
	}
	return (x);
}

int	find_c(t_temp *tmp, char *check)
{
	if (tmp->j)
		tmp->j++;
	while (check[tmp->j])
	{
		if (check[tmp->j] == 'C')
			return (tmp->j);
		tmp->j++;
	}
	return (0);
}
