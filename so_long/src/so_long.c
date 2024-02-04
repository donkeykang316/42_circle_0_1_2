/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:35:12 by kaan              #+#    #+#             */
/*   Updated: 2024/02/04 01:02:45 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_check(t_data *game)
{
	t_temp		*tmp;
	char		*check;

	check = NULL;
	tmp = tmp_init(game);
	while (tmp->temp)
	{
		if (tmp->temp)
			check = ft_strjoin(check, tmp->temp);
		free (tmp->temp);
		tmp->temp = get_next_line(tmp->fd);
	}
	tmp->i = 0;
	tmp->count = 0;
	while (check[tmp->i])
	{
		while (check[tmp->i] != 10)
			tmp->i++;
		tmp->count++;
		if (tmp->x)
		{
			//ft_printf("i:%d x:%d\n", tmp->i, tmp->x);
			if ((tmp->i - tmp->count) / 2 == tmp->x)
			{
				ft_printf("ERROR\n");
				exit(0);
			}
		}
		else
			tmp->x = tmp->i;
		ft_printf("i:%d x:%d\n", tmp->i, tmp->x);
		tmp->i++;
	}
	free(check);
	close (tmp->fd);
	free_tmp(tmp);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_data));
		if (!game)
			exit(0);
		game->filename = ft_strdup(av[1]);
		if (!game->filename)
		{
			free(game);
			exit(0);
		}
		map_check(game);
		open_display(game);
		game->step = 0;
		gametile_init(game);
		mlx_hook(game->win_ptr, 2, 1L << 0, &input_manager, game);
		mlx_hook(game->win_ptr, 17, 0, &close_display, game);
		mlx_loop(game->mlx_ptr);
	}
	else
		ft_printf("Wrong entry, insert the MAP FILE\n");
}
