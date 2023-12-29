/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2023/12/29 12:38:36 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_list		**stack_a;
	t_list		*new;

	i = 1;
	stack_a = malloc(ac * sizeof (t_list));
	*stack_a = NULL;
	if (ac >= 2)
	{
		while (av[i])
		{
			new = ft_lstnew(av[i]);
			ft_lstadd_back(stack_a, new);
			i++;
		}
	ft_printf("%d\n", ft_atoi((*stack_a)->content));
	}
	free(new);
	free(stack_a);
}
