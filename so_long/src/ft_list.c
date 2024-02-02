/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:49:16 by kaan              #+#    #+#             */
/*   Updated: 2024/02/02 09:22:56 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_map	*ft_lstlast_doub(t_map *lst)
{
	t_map	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_map	*ft_lstnew_doub(char *content)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		exit(1);
	new->line = ft_strdup(content);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back_doub(t_map **lst, t_map *new)
{
	t_map	*last;

	last = ft_lstlast_doub(*lst);
	if (!last)
	{
		*lst = new;
		new->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

int	ft_lstsize_doub(t_map *lst)
{
	t_map	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
