/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 07:55:54 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 16:37:55 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_cow_d(t_data *game, t_map **cow)
{
	if ((*cow)->x == -1)
		*cow = find_cow(cow);
	if ((*cow)->line[(*cow)->x + 1] == 'E' && win_check(*cow) == 1)
	{
		game->step++;
		ft_printf("step:%d\n", game->step);
		close_display(game);
	}
	else if ((*cow)->line[(*cow)->x + 1] == '0'
		|| (*cow)->line[(*cow)->x + 1] == 'C')
	{
		(*cow)->line[(*cow)->x] = '0';
		(*cow)->x += 1;
		(*cow)->line[(*cow)->x] = 'P';
		game->step++;
		ft_printf("step:%d\n", game->step);
		display_bg(game, *cow);
	}
}

void	move_cow_a(t_data *game, t_map **cow)
{
	if ((*cow)->x == -1)
		*cow = find_cow(cow);
	if ((*cow)->line[(*cow)->x - 1] == 'E' && win_check(*cow) == 1)
	{
		game->step++;
		ft_printf("step:%d\n", game->step);
		close_display(game);
	}
	else if ((*cow)->line[(*cow)->x - 1] == '0'
		|| (*cow)->line[(*cow)->x - 1] == 'C')
	{
		(*cow)->line[(*cow)->x] = '0';
		(*cow)->x -= 1;
		(*cow)->line[(*cow)->x] = 'P';
		game->step++;
		ft_printf("step:%d\n", game->step);
		display_bg(game, *cow);
	}
}

void	move_cow_w(t_data *game, t_map **cow)
{
	int	x;

	if ((*cow)->x == -1)
		*cow = find_cow(cow);
	if ((*cow)->prev->line[(*cow)->x] == 'E' && win_check(*cow) == 1)
	{
		game->step++;
		ft_printf("step:%d\n", game->step);
		close_display(game);
	}
	else if ((*cow)->prev->line[(*cow)->x] == '0'
		|| (*cow)->prev->line[(*cow)->x] == 'C')
	{
		(*cow)->line[(*cow)->x] = '0';
		x = (*cow)->x;
		(*cow) = (*cow)->prev;
		(*cow)->x = x;
		(*cow)->line[(*cow)->x] = 'P';
		game->step++;
		ft_printf("step:%d\n", game->step);
		display_bg(game, *cow);
	}
}

void	move_cow_s(t_data *game, t_map **cow)
{
	int	x;

	if ((*cow)->x == -1)
		*cow = find_cow(cow);
	if ((*cow)->next->line[(*cow)->x] == 'E' && win_check(*cow) == 1)
	{
		game->step++;
		ft_printf("step:%d\n", game->step);
		close_display(game);
	}
	else if ((*cow)->next->line[(*cow)->x] == '0'
		|| (*cow)->next->line[(*cow)->x] == 'C')
	{
		(*cow)->line[(*cow)->x] = '0';
		x = (*cow)->x;
		(*cow) = (*cow)->next;
		(*cow)->x = x;
		(*cow)->line[(*cow)->x] = 'P';
		game->step++;
		ft_printf("step:%d\n", game->step);
		display_bg(game, (*cow)->prev);
	}
}
