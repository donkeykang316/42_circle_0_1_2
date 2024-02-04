/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:48:13 by kaan              #+#    #+#             */
/*   Updated: 2024/02/05 00:09:11 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_map	*map_init(t_data *game)
{
	t_map	*m_line;

	m_line = NULL;
	m_line = map_list(game, m_line);
	return (m_line);
}

int	input_manager(int keypress, t_data *game, t_map **m_line)
{
	if (keypress == 65307)
	{
		close_display(game);
		exit (0);
	}
	if (!(*m_line))
		*m_line = map_init(game);
	game->map = m_line;
	if (keypress == 65293)
		display_bg(game, *m_line);
	else if (m_line)
	{
		display_bg(game, *m_line);
		if (keypress == 97 || keypress == 65361)
			move_cow_a(game, m_line);
		if (keypress == 100 || keypress == 65363)
			move_cow_d(game, m_line);
		if (keypress == 119 || keypress == 65362)
			move_cow_w(game, m_line);
		if (keypress == 115 || keypress == 65364)
			move_cow_s(game, m_line);
	}
	return (0);
}
