/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:35:12 by kaan              #+#    #+#             */
/*   Updated: 2024/02/04 18:06:06 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*void	find_p(t_temp *tmp, char *check)
{
	tmp->i = 0;
	while (check[tmp->i])
	{
		if (check[tmp->i] == 'P')
			return ;
		tmp->i++;
	}
}

void	path_validation(t_data *game, t_temp *tmp, char *check)
{
	find_p(tmp, check);
	while (check[tmp->i] != 'C')
	{
		if (check[tmp->i + 1] != '1')
			tmp->i += 1;
		else if (check[tmp->i + 16] != '1')
			tmp->i += 16;
		else if (check[tmp->i - 1] != '1')
			tmp->i - 1;
		else if (check[tmp->i - 16] != '1')
			tmp->i -= 16;
		ft_printf("i:%d\n", tmp->i);
		ft_printf("check:%c\n", check[tmp->i]);
	}
	ft_printf("i:%d\n", tmp->i);
}*/

void	map_check(t_data *game)
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
	mwidth_check(game, tmp, check);
	rectangle_check(game, tmp, check);
	wall_check(game, tmp, check);
	item_check(game, tmp, check);
	//path_validation(game, tmp, check);
	free(check);
	close (tmp->fd);
	free_tmp(tmp);
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
