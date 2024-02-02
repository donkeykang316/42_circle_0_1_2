/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:23:04 by kaan              #+#    #+#             */
/*   Updated: 2024/02/02 15:56:26 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_tile	*water_tile(t_data *game)
{
	t_tile	*water;

	water = NULL;
	water = malloc(sizeof(t_tile));
	if (!water)
	{
		free(water);
		exit (0);
	}
	water->f_name = ft_strdup("./tile/water.xpm");
	if (!water->f_name)
	{
		free(water);
		exit (0);
	}
	water->img = mlx_xpm_file_to_image(game->mlx_ptr,
			water->f_name,
			&water->width,
			&water->height);
	if (!water->img)
	{
		free(water->f_name);
		free(water);
		exit (0);
	}
	game->water = water;
	return (water);
}

t_tile	*dirt_tile(t_data *game)
{
	t_tile	*dirt;

	dirt = NULL;
	dirt = malloc(sizeof(t_tile));
	if (!dirt)
	{
		free(dirt);
		exit (0);
	}
	dirt->f_name = ft_strdup("./tile/dirt.xpm");
	if (!dirt->f_name)
	{
		free(dirt);
		exit (0);
	}
	dirt->img = mlx_xpm_file_to_image(game->mlx_ptr,
			dirt->f_name,
			&dirt->width,
			&dirt->height);
	if (!dirt->img)
	{
		free(dirt->f_name);
		free(dirt);
		exit (0);
	}
	game->dirt = dirt;
	return (dirt);
}

t_tile	*goal_tile(t_data *game)
{
	t_tile	*goal;

	goal = NULL;
	goal = malloc(sizeof(t_tile));
	if (!goal)
	{
		free(goal);
		exit (0);
	}
	goal->f_name = ft_strdup("./tile/goal.xpm");
	if (!goal->f_name)
	{
		free(goal);
		exit (0);
	}
	goal->img = mlx_xpm_file_to_image(game->mlx_ptr,
			goal->f_name,
			&goal->width,
			&goal->height);
	if (!goal->img)
	{
		free(goal->f_name);
		free(goal);
		exit (0);
	}
	game->goal = goal;
	return (goal);
}

t_tile	*cha_tile(t_data *game)
{
	t_tile	*cha;

	cha = NULL;
	cha = malloc(sizeof(t_tile));
	if (!cha)
	{
		free(cha);
		exit (0);
	}
	cha->f_name = ft_strdup("./tile/cow.xpm");
	if (!cha->f_name)
	{
		free(cha);
		exit (0);
	}
	cha->img = mlx_xpm_file_to_image(game->mlx_ptr,
			cha->f_name,
			&cha->width,
			&cha->height);
	if (!cha->img)
	{
		free(cha->f_name);
		free(cha);
		exit (0);
	}
	game->cha = cha;
	return (cha);
}

t_tile	*egg_tile(t_data *game)
{
	t_tile	*egg;

	egg = NULL;
	egg = malloc(sizeof(t_tile));
	if (!egg)
	{
		free(egg);
		exit (0);
	}
	egg->f_name = ft_strdup("./tile/egg.xpm");
	if (!egg->f_name)
	{
		free(egg);
		exit (0);
	}
	egg->img = mlx_xpm_file_to_image(game->mlx_ptr,
			egg->f_name,
			&egg->width,
			&egg->height);
	if (!egg->img)
	{
		free(egg->f_name);
		free(egg);
		exit (0);
	}
	game->egg = egg;
	return (egg);
}
