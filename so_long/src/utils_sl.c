/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:24:40 by kaan              #+#    #+#             */
/*   Updated: 2024/02/01 00:25:18 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_tile	*enter_tile(t_data *game)
{
	t_tile	*enter;

	enter = NULL;
	enter = malloc(sizeof(t_tile));
	if (!enter)
	{
		free(enter);
		exit (0);
	}
	enter->f_name = ft_strdup("./tile/enter.xpm");
	enter->img = mlx_xpm_file_to_image(game->mlx_ptr,
			enter->f_name,
			&enter->width,
			&enter->height);
	return (enter);
}

void	ft_free(t_data *game)
{
	free(game->mlx_ptr);
	free(game->win_ptr);
	free(game);
}

void	open_display(t_data *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 960, 640, "Try to WIN");
	display_enter(game);
}

int	close_display(t_data *game)
{
	if (game->win_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr != NULL)
		mlx_destroy_display(game->mlx_ptr);
	exit (0);
	free(game);
	return (0);
}
