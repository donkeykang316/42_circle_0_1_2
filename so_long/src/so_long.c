/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:35:12 by kaan              #+#    #+#             */
/*   Updated: 2024/02/05 16:44:11 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		map_filename_check(game);
		map_check(game);
		open_display(game);
		game->step = 0;
		gametile_init(game);
		game->map = NULL;
		mlx_hook(game->win_ptr, 2, 1L << 0, &input_manager, game);
		mlx_hook(game->win_ptr, 17, 0, &close_display, game);
		mlx_loop(game->mlx_ptr);
	}
	else
		ft_printf("Wrong entry, insert the MAP FILE\n");
}
