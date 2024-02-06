/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:45:49 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 16:38:44 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tile_put_img(t_data *game, t_map *m_line, t_tile *tile, int coor)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr,
		tile->img,
		tile->width = game->x * coor,
		tile->height = m_line->index * coor);
}

void	gametile_init(t_data *game)
{
	game->cow = NULL;
	game->egg = NULL;
	game->water = NULL;
	game->dirt = NULL;
	game->goal = NULL;
	if (!game->cow && !game->egg && !game->water && !game->dirt && !game->goal)
	{
		game->cow = cow_tile(game);
		tile_value_init(game->cow);
		game->egg = egg_tile(game);
		tile_value_init(game->egg);
		game->water = water_tile(game);
		tile_value_init(game->water);
		game->dirt = dirt_tile(game);
		tile_value_init(game->dirt);
		game->goal = goal_tile(game);
		tile_value_init(game->goal);
	}
}

void	display_bg(t_data *game, t_map	*m_line)
{

	while (m_line)
	{
		game->x = 0;
		while (m_line->line[game->x] != 10)
		{
			if (m_line->line[game->x] == '1')
				tile_put_img(game, m_line, game->water, 64);
			else if (m_line->line[game->x] == 'P')
				tile_put_img(game, m_line, game->cow, 64);
			else if (m_line->line[game->x] == 'C')
				tile_put_img(game, m_line, game->egg, 64);
			else if (m_line->line[game->x] == '0')
				tile_put_img(game, m_line, game->dirt, 64);
			else if (m_line->line[game->x] == 'E')
				tile_put_img(game, m_line, game->goal, 63);
			game->x++;
		}
		m_line = m_line->next;
	}
}

t_map	*find_cow(t_map **cow)
{
	while (*cow)
	{
		(*cow)->x = 0;
		while ((*cow)->line[(*cow)->x] != 10)
		{
			if ((*cow)->line[(*cow)->x] == 'P')
				return (*cow);
			(*cow)->x++;
		}
		(*cow) = (*cow)->next;
	}
	return (*cow);
}

int	win_check(t_map *card)
{
	int	i;

	while (card->prev)
		card = card->prev;
	while (card->next)
	{
		i = 0;
		while (card->line[i] != 10)
		{
			if (card->line[i] == 'C')
				return (0);
			i++;
		}
		card = card->next;
	}
	return (1);
}
