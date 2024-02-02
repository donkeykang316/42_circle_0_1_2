/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:00:27 by kaan              #+#    #+#             */
/*   Updated: 2024/02/02 09:35:52 by kaan             ###   ########.fr       */
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
	game->enter = enter;
	return (enter);
}

t_tile	*won_tile(t_data *game)
{
	t_tile	*won;

	won = NULL;
	won = malloc(sizeof(t_tile));
	if (!won)
	{
		free(won);
		exit (0);
	}
	won->f_name = ft_strdup("./tile/won.xpm");
	won->img = mlx_xpm_file_to_image(game->mlx_ptr,
			won->f_name,
			&won->width,
			&won->height);
	game->won = won;
	return (won);
}
