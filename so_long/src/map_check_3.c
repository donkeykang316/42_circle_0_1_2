/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:22:20 by kaan              #+#    #+#             */
/*   Updated: 2024/02/04 23:24:27 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	find_p(t_temp *tmp, char *check)
{
	if (tmp->temp)
		free (tmp->temp);
	tmp->temp = NULL;
	tmp->temp = ft_strdup(check);
	tmp->i = 0;
	while (check[tmp->i])
	{
		if (check[tmp->i] == 'P')
			return ;
		tmp->i++;
	}
}

int	flood_fill_c(char *check, int p_po)
{
	if (p_po < 0 || check[p_po] == '1' || check[p_po] == 'E')
		return (0);
	if (check[p_po] == 'C')
		return (1);
	check[p_po] = '1';
	if (flood_fill_c(check, p_po - 16)
		|| flood_fill_c(check, p_po + 16)
		|| flood_fill_c(check, p_po - 1)
		|| flood_fill_c(check, p_po + 1))
		return (1);
	return (0);
}

int	flood_fill_e(char *check, int p_po)
{
	if (p_po < 0 || check[p_po] == '1')
		return (0);
	if (check[p_po] == 'E')
		return (1);
	check[p_po] = '1';
	if (flood_fill_e(check, p_po - 16)
		|| flood_fill_e(check, p_po + 16)
		|| flood_fill_e(check, p_po - 1)
		|| flood_fill_e(check, p_po + 1))
		return (1);
	return (0);
}

void	path_validation(t_data *game, t_temp *tmp, char *check)
{
	find_p(tmp, check);
	if (flood_fill_c(tmp->temp, tmp->i) == 1)
	{
		find_p(tmp, check);
		if (flood_fill_e(tmp->temp, tmp->i) == 1)
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
