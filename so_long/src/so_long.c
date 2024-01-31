/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:35:12 by kaan              #+#    #+#             */
/*   Updated: 2024/01/31 16:28:29 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

t_cha	*cha_tile(t_data *game)
{
	t_cha	*cha;

	cha = malloc(sizeof(t_cha));
	if (!cha)
	{
		free(cha);
		exit (0);
	}
	cha->f_name = ft_strdup("./tile/cow.xpm");
	cha->img = mlx_xpm_file_to_image(game->mlx_ptr,
			cha->f_name,
			&cha->x,
			&cha->y);
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

t_map	*display_bg(t_data *game)
{
	static char	*map_1 = NULL;
	int			m_l;
	int			i;
	int			x;
	int			y;
	t_map		*card;
	t_tile		*water;
	t_tile		*dirt;
	t_tile		*goal;
	t_tile		*egg;

	m_l = 10;
	i = 0;
	x = 0;
	y = 0;
	water = water_tile(game);
	dirt = dirt_tile(game);
	goal = goal_tile(game);
	egg = egg_tile(game);
	egg->width = 0;
	egg->height = 0;
	water->width = 0;
	water->height = 0;
	dirt->width = 0;
	dirt->height = 0;
	goal->width = 0;
	goal->height = 0;
	game->filename = ft_strdup("./map/map_1.ber");
	game->fd = open(game->filename, O_RDONLY);
	ft_printf("fd:%d\n", game->fd);
	//go for new loop function, use link list
	while (game->fd == 4)
	{
		ft_printf("loop_fd:%d\n", game->fd);
		if (!map_1)
			map_1 = get_next_line(game->fd);
		else
			map_1 = ft_strjoin(map_1, get_next_line(game->fd));
	}
	card = NULL;
	card = malloc(sizeof(t_map));
	card->map = malloc(ft_strlen(map_1) + 1);
	ft_strlcpy(card->map, map_1, ft_strlen(map_1));
	close (game->fd);
	while (card->map[i] && y != 11)
	{
		if (card->map[i] == '1')
		{
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr,
				water->img,
				water->width = x * 64,
				water->height = y * 64);
		}
		else if (card->map[i] == 'C')
		{
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr,
				egg->img,
				egg->width = x * 64,
				egg->height = y * 64);
		}
		else if (card->map[i] == '0' || card->map[i] == 'P')
		{
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr,
				dirt->img,
				dirt->width = x * 64,
				dirt->height = y * 64);
		}
		else if (card->map[i] == 'E')
		{
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr,
				goal->img,
				goal->width = x * 63,
				goal->height = y * 63);
		}
		else if (card->map[i] == '\n')
		{
			x = -1;
			y++;
		}
		i++;
		x++;
	}
	return (card);
}

void	move_cow(t_data *game, int keypress)
{
	//WIP
	t_map	*card;
	t_cha	*cow;
	int		i;

	i = 0;
	cow = cha_tile(game);
	cow->x = 0;
	cow->y = 0;
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr,
		cow->img,
		cow->x,
		cow->y);
	card = display_bg(game);
	while (card)
	{
		if (keypress == 100)
		{
			card->map[i] = '0';
			i += 1;
			card->map[i] = 'P'; 
		}
		//display_bg(game);
	}
}

int	input_manager(int keypress, t_data *game, t_map *card)
{
	ft_printf("key:%d\n", keypress);
	ft_printf("map:%s\n", card->map);
	if (keypress == 65307)
	{
		close_display(game);
		exit(0);
	}
	else if (/*keypress == 97 || */keypress == 100)
	{
		move_cow(game, keypress);
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
