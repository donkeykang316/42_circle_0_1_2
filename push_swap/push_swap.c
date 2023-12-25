/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2023/12/25 12:58:21 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_list		**a;

	i = 1;
	a[0] = *a;	
	*a = NULL;
	if (ac >= 2)
	{
		while (av[i])
		{
			*a = ft_lstnew(av[i]);
			ft_printf("%d\n", ft_atoi(*a->content));
			free(*a);
			i++;
			*a = *a->next;
		}
		//ft_printf("size:%d\n", ft_lstsize(*a));
	}
}
