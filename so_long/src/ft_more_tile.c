/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:00:27 by kaan              #+#    #+#             */
/*   Updated: 2024/02/03 23:53:21 by kaan             ###   ########.fr       */
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
