/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/04 13:35:58 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacking(t_list **stack_a, int ac, char **av)
{
	t_list	*new;
	int		i;

	i = 1;
	if (ac >= 2)
	{
		new = NULL;
		while (av[i])
		{
			new = ft_lstnew(ft_atoi(av[i]));
			ft_lstadd_back(stack_a, new);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	t_list		*stack_a;

	stack_a = malloc(sizeof (t_list));
	stack_a = NULL;
	stacking(&stack_a, ac, av);
}
