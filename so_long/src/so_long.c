/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:35:12 by kaan              #+#    #+#             */
/*   Updated: 2024/01/30 23:22:59 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free(t_data *game);
void	open_display(t_data *game);
int		close_display(t_data *game);
void	display_bg(t_data *game);
int		input_manager(int keypress, t_data *game);
t_tile	*water_tile(t_data *game);
t_tile	*dirt_tile(t_data *game);
t_tile	*cha_tile(t_data *game);
t_tile	*egg_tile(t_data *game);
t_tile	*goal_tile(t_data *game);

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
	display_bg(game);
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

t_tile	*water_tile(t_data *game)
{
	t_tile	*water;

	water = malloc(sizeof(t_tile));
	if (!water)
	{
		free(water);
		exit (0);
	}
	water->f_name = ft_strdup("./tile/water.xpm");
	water->img = mlx_xpm_file_to_image(game->mlx_ptr,
			water->f_name,
			&water->width,
			&water->height);
	return (water);
}

t_tile	*dirt_tile(t_data *game)
{
	t_tile	*dirt;

	dirt = malloc(sizeof(t_tile));
	if (!dirt)
	{
		free(dirt);
		exit (0);
	}
	dirt->f_name = ft_strdup("./tile/dirt.xpm");
	dirt->img = mlx_xpm_file_to_image(game->mlx_ptr,
			dirt->f_name,
			&dirt->width,
			&dirt->height);
	return (dirt);
}

t_tile	*goal_tile(t_data *game)
{
	t_tile	*goal;

	goal = malloc(sizeof(t_tile));
	if (!goal)
	{
		free(goal);
		exit (0);
	}
	goal->f_name = ft_strdup("./tile/goal.xpm");
	goal->img = mlx_xpm_file_to_image(game->mlx_ptr,
			goal->f_name,
			&goal->width,
			&goal->height);
	return (goal);
}

t_tile	*cha_tile(t_data *game)
{
	t_tile	*cha;

	cha = malloc(sizeof(t_tile));
	if (!cha)
	{
		free(cha);
		exit (0);
	}
	cha->f_name = ft_strdup("./tile/cow.xpm");
	cha->img = mlx_xpm_file_to_image(game->mlx_ptr,
			cha->f_name,
			&cha->width,
			&cha->height);
	return (cha);
}

t_tile	*egg_tile(t_data *game)
{
	t_tile	*egg;

	egg = malloc(sizeof(t_tile));
	if (!egg)
	{
		free(egg);
		exit (0);
	}
	egg->f_name = ft_strdup("./tile/egg.xpm");
	egg->img = mlx_xpm_file_to_image(game->mlx_ptr,
			egg->f_name,
			&egg->width,
			&egg->height);
	return (egg);
}

void	display_bg(t_data *game)
{
	t_tile		*water;
	t_tile		*dirt;
	t_tile		*goal;
	t_tile		*cha;
	t_tile		*egg;
	char		*map;
	int			fd;
	int			i;
	int			j;

	j = 0;
	water = water_tile(game);
	dirt = dirt_tile(game);
	goal = goal_tile(game);
	cha = cha_tile(game);
	egg = egg_tile(game);
	egg->width = 0;
	egg->height = 0;
	cha->width = 0;
	cha->height = 0;
	water->width = 0;
	water->height = 0;
	dirt->width = 0;
	dirt->height = 0;
	goal->width = 0;
	goal->height = 0;
	game->filename = ft_strdup("./map/map_1.ber");
	fd = open(game->filename, O_RDONLY);
	while (j != 10)
	{
		map = get_next_line(fd);
		i = 0;
		while (map[i] != 10)
		{
			if (map[i] == '1')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					water->img,
					water->width = i * 64,
					water->height = j * 64);
			}
			else if (map[i] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					cha->img,
					cha->width = i * 64,
					cha->height = j * 64);
			}
			else if (map[i] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					egg->img,
					egg->width = i * 64,
					egg->height = j * 64);
			}
			else if (map[i] == '0')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					dirt->img,
					dirt->width = i * 64,
					dirt->height = j * 64);
			}
			else if (map[i] == 'E')
			{
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr,
					goal->img,
					goal->width = i * 63,
					goal->height = j * 63);
			}
			i++;
		}
		free(map);
		j++;
	}
	close(fd);
}

int	input_manager(int keypress, t_data *game)
{
	ft_printf("key:%d\n", keypress);
	if (keypress == 65307)
	{
		close_display(game);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	open_display(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, &input_manager, game);
	mlx_hook(game->win_ptr, 17, 0, close_display, game);
	mlx_loop(game->mlx_ptr);
}
