/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:49:39 by kaan              #+#    #+#             */
/*   Updated: 2024/02/06 16:38:26 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_validation(t_data *game, t_temp *tmp, char *check)
{
	if (flood_multiple_c(game, tmp, check) == 1)
	{
		find_p(tmp, check);
		if (flood_fill_e(game, tmp->temp, tmp->i) == 1)
			return ;
		else
		{
			ft_printf("ERROR\nNO valid e-path\n");
			free_mapcheck(game, tmp, check);
			exit(0);
		}
	}
	else
	{
		ft_printf("ERROR\nNO valid c-path\n");
		free_mapcheck(game, tmp, check);
		exit(0);
	}
}

void	map_filename_check(t_data *game)
{
	char	*temp;

	temp = ft_strnstr(game->filename, ".ber", ft_strlen(game->filename));
	if (!temp)
	{
		ft_printf("ERROR\nWrong Map format\n");
		free(game->filename);
		free(game);
		free(temp);
		exit (0);
	}
}

int	flood_multiple_c(t_data *game, t_temp *tmp, char *check)
{
	char	*check_temp;
	int		bool;
	int		x;

	tmp->j = 0;
	bool = 0;
	check_temp = NULL;
	x = c_count(check);
	while (x)
	{
		check_temp = ft_strdup(check);
		tmp->j = find_c(tmp, check_temp);
		bool = flood_fill_c(game, check_temp, tmp->j);
		free(check_temp);
		if (bool == 0)
			return (bool);
		x--;
	}
	return (bool);
}
