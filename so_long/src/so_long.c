/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:35:12 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 20:06:50 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free(t_list *game)
{
	free(game->mlx_ptr);
	free(game->win_ptr);
	free(game);
}

void	open_display(t_list *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_free(game->mlx_ptr);
		return ;
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1000, 500, "Try to WIN");
	if (!game->win_ptr)
	{
		ft_free(game->win_ptr);
		return ;
	}
}

void	close_display(t_list *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
}

void	display_bg(t_list *game)
{
	int		x;
	int		y;

	y = 30;
	while (y != 470)
	{
		x = 30;
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, 0x0fff0);
		while (x != 970)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, 0x0fff0);
			x++;
		}
		y++;
	}
	mlx_loop(game->mlx_ptr);
}

int	main(void)
{
	t_list	*game;

	game = malloc(sizeof(t_list));
	open_display(game);
	display_bg(game);
	close_display(game);
	ft_free(game);
}
