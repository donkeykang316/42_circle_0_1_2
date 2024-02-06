/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:23:04 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 16:38:05 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	*water_tile(t_data *game)
{
	game->water = malloc(sizeof(t_tile));
	if (!game->water)
		exit (0);
	game->water->f_name = ft_strdup("./tile/water.xpm");
	if (!game->water->f_name)
	{
		free(game->water);
		exit (0);
	}
	game->water->img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->water->f_name,
			&game->water->width,
			&game->water->height);
	if (!game->water->img)
	{
		free(game->water->f_name);
		free(game->water);
		exit (0);
	}
	free(game->water->f_name);
	return (game->water);
}

t_tile	*dirt_tile(t_data *game)
{
	game->dirt = malloc(sizeof(t_tile));
	if (!game->dirt)
		exit (0);
	game->dirt->f_name = ft_strdup("./tile/dirt.xpm");
	if (!game->dirt->f_name)
	{
		free(game->dirt);
		exit (0);
	}
	game->dirt->img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->dirt->f_name,
			&game->dirt->width,
			&game->dirt->height);
	if (!game->dirt->img)
	{
		free(game->dirt->f_name);
		free(game->dirt);
		exit (0);
	}
	free(game->dirt->f_name);
	return (game->dirt);
}

t_tile	*goal_tile(t_data *game)
{
	game->goal = malloc(sizeof(t_tile));
	if (!game->goal)
		exit (0);
	game->goal->f_name = ft_strdup("./tile/goal.xpm");
	if (!game->goal->f_name)
	{
		free(game->goal);
		exit (0);
	}
	game->goal->img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->goal->f_name,
			&game->goal->width,
			&game->goal->height);
	if (!game->goal->img)
	{
		free(game->goal->f_name);
		free(game->goal);
		exit (0);
	}
	free(game->goal->f_name);
	return (game->goal);
}

t_tile	*cow_tile(t_data *game)
{
	game->cow = malloc(sizeof(t_tile));
	if (!game->cow)
		exit (0);
	game->cow->f_name = ft_strdup("./tile/cow.xpm");
	if (!game->cow->f_name)
		exit (0);
	game->cow->img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->cow->f_name,
			&game->cow->width,
			&game->cow->height);
	if (!game->cow->img)
	{
		free(game->cow->f_name);
		free(game->cow);
		exit (0);
	}
	free(game->cow->f_name);
	return (game->cow);
}

t_tile	*egg_tile(t_data *game)
{
	game->egg = malloc(sizeof(t_tile));
	if (!game->egg)
		exit (0);
	game->egg->f_name = ft_strdup("./tile/egg.xpm");
	if (!game->egg->f_name)
	{
		free(game->egg);
		exit (0);
	}
	game->egg->img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->egg->f_name,
			&game->egg->width,
			&game->egg->height);
	if (!game->egg->img)
	{
		free(game->egg->f_name);
		free(game->egg);
		exit (0);
	}
	free(game->egg->f_name);
	return (game->egg);
}
