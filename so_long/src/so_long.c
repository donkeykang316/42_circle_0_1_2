/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:35:12 by kaan              #+#    #+#             */
/*   Updated: 2024/01/29 17:30:04 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free(t_data *game);
void	open_display(t_data *game, t_map *water);
void	close_display(t_data *game);
void	display_bg(t_data *game, t_map *water);
int		input_manager(int keypress, t_data *game);

void	ft_free(t_data *game)
{
	free(game->mlx_ptr);
	free(game->win_ptr);
	free(game);
}

void	open_display(t_data *game, t_map *water)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1000, 500, "Try to WIN");
	display_bg(game, water);
}

void	close_display(t_data *game)
{
	if (game->win_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr != NULL)
		mlx_destroy_display(game->mlx_ptr);
	free(game);
}

void	display_bg(t_data *game, t_map *water)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->f_name = ft_strdup("./water.xpm");
	game->height = 100;
	game->width = 100;
	water->height = 250;
	water->width = 350;
	water->img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->f_name,
			&game->width,
			&game->height);
	while (x != 499)
	{
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr,
			water->img,
			water->width + x,
			water->height);
		while (y != 499)
		{
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr,
				water->img,
				water->width + x,
				water->height + y);
		}
		x++;
	}
}

int	input_manager(int keypress, t_data *game)
{
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
	t_map	*tile;

	game = malloc(sizeof(t_data));
	tile = malloc(sizeof(t_map));
	open_display(game, tile);
	mlx_hook(game->win_ptr, 2, 1L << 0, &input_manager, game);
	mlx_loop(game->mlx_ptr);
}
