/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/04 18:08:42 by kaan             ###   ########.fr       */
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

void	push_b(t_list *stack_a, t_list **stack_b)
{
	ft_lstadd_back(stack_b, stack_a);
	free(stack_a);
	stack_a = stack_a->next;
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
	push_b(stack_a, &stack_b);

	ft_printf("%d\n", stack_b->content);
	ft_printf("%d\n", stack_a->content);
	stack_b = stack_b->next;
}
