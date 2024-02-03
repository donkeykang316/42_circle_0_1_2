/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:00:27 by kaan              #+#    #+#             */
/*   Updated: 2024/02/03 20:48:55 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_tile	*enter_tile(t_data *game)
{
	game->enter = malloc(sizeof(t_tile));
	if (!game->enter)
		exit (0);
	game->enter->f_name = ft_strdup("./tile/enter.xpm");
	if (!game->enter->f_name)
	{
		free(game->enter);
		exit (0);
	}
	game->enter->img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->enter->f_name,
			&game->enter->width,
			&game->enter->height);
	if (!game->enter->img)
	{
		free(game->enter->f_name);
		free(game->enter);
		exit (0);
	}
	free(game->enter->f_name);
	return (game->enter);
}

t_tile	*won_tile(t_data *game)
{
	game->won = malloc(sizeof(t_tile));
	if (!game->won)
		exit (0);
	game->won->f_name = ft_strdup("./tile/won.xpm");
	if (!game->won->f_name)
	{
		free(game->won);
		exit (0);
	}
	game->won->img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->won->f_name,
			&game->won->width,
			&game->won->height);
	if (!game->won->img)
	{
		free(game->won->f_name);
		free(game->won);
		exit (0);
	}
	free(game->won->f_name);
	return (game->won);
}
