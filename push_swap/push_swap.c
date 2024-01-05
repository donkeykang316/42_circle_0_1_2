/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/05 12:42:55 by kaan             ###   ########.fr       */
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

void	push(t_list **stack, t_list **node)
{
	t_list	*new;

	new = ft_lstnew((*node)->content);
	ft_lstadd_back(stack, new);
	if (*node && (*node)->next)
	{
		*node = (*node)->next;
	}
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = malloc(sizeof (t_list));
	stack_b = malloc(sizeof (t_list));
	stack_a = NULL;
	stack_b = NULL;
	stacking(&stack_a, ac, av);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);

	ft_printf("%d\n", ft_lstsize(stack_a));
	ft_printf("%d\n", stack_a->content);
	ft_printf("%d\n", stack_b->content);
	ft_printf("%d\n", ft_lstsize(stack_b));
}
