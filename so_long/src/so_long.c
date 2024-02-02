/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:35:12 by kaan              #+#    #+#             */
/*   Updated: 2024/02/02 11:07:41 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


t_map	*map_list(t_data *game, t_map *m_line)
{
	t_map		*new;
	char		*temp;
	int			i;

	i = 0;
	new = NULL;
	temp = NULL;
	new = malloc(sizeof(t_map));
	game->fd = open(game->filename, O_RDONLY);
	temp = get_next_line(game->fd);
	if (!temp)
	{
		ft_printf("NO FILE\n");
		free(temp);
	}
	new = ft_lstnew_doub(temp);
	new->index = i++;
	new->x = -1;
	ft_lstadd_back_doub(&m_line, new);
	while (temp)
	{
		temp = get_next_line(game->fd);
		if (temp)
		{
			new = ft_lstnew_doub(temp);
			new->index = i;
			new->x = -1;
			ft_lstadd_back_doub(&m_line, new);
			i++;
		}
		free(temp);
	}
	close (game->fd);
	return (m_line);
}

void	display_enter(t_data *game)
{
	t_tile		*enter;

	enter = enter_tile(game);
	enter->width = 350;
	enter->height = 192;
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr,
		enter->img,
		enter->width,
		enter->height);
}

void	display_won(t_data *game)
{
	t_tile		*won;

	won = won_tile(game);
	won->width = 0;
	won->height = 0;
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr,
		won->img,
		won->width,
		won->height);
}

void	display_bg(t_data *game, t_map	*m_line)
{
	t_tile		*water;
	t_tile		*dirt;
	t_tile		*goal;
	t_tile		*egg;
	t_tile		*cow;
	int			x;

	water = water_tile(game);
	dirt = dirt_tile(game);
	goal = goal_tile(game);
	egg = egg_tile(game);
	cow = cha_tile(game);
	cow->width = 0;
	cow->height = 0;
	egg->width = 0;
	egg->height = 0;
	water->width = 0;
	water->height = 0;
	dirt->width = 0;
	dirt->height = 0;
	goal->width = 0;
	goal->height = 0;
	while (m_line)
	{
		x = 0;
		while (m_line->line[x] != 10)
		{
			if (m_line->line[x] == '1')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					water->img,
					water->width = x * 64,
					water->height = m_line->index * 64);
			}
			else if (m_line->line[x] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					cow->img,
					cow->width = x * 64,
					cow->height = m_line->index * 64);
			}
			else if (m_line->line[x] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					egg->img,
					egg->width = x * 64,
					egg->height = m_line->index * 64);
			}
			else if (m_line->line[x] == '0')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					dirt->img,
					dirt->width = x * 64,
					dirt->height = m_line->index * 64);
			}
			else if (m_line->line[x] == 'E')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					goal->img,
					goal->width = x * 63,
					goal->height = m_line->index * 63);
			}
			x++;
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

t_map	*map_init(t_data *game)
{
	t_map	*m_line;

	m_line = NULL;
	m_line = map_list(game, m_line);
	return (m_line);
}

int	input_manager(int keypress, t_data *game, t_map **m_line)
{
	if (!(*m_line))
		*m_line = map_init(game);
	ft_printf("key:%d\n", keypress);
	if (keypress == 65307)
	{
		close_display(game, m_line);
		exit (0);
	}
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

int	main(int ac, char **av)
{
	t_data	*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_data));
		game->filename = ft_strdup(av[1]);
		open_display(game);
		mlx_hook(game->win_ptr, 2, 1L << 0, &input_manager, game);
		mlx_loop(game->mlx_ptr);
		mlx_hook(game->win_ptr, 17, 0, close_display, game);
	}
	else
		ft_printf("Wrong entry, insert the MAP FILE\n");
}
