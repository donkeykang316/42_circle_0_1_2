/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/06 15:49:29 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	push(stack_b, stack_a);
	ft_printf("%d\n", ft_lstsize(*stack_a));
	ft_printf("%d\n", ft_lstsize(*stack_b));
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
	if (order_check(&stack_a) == 0)
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
		{
			sort_thr(&stack_a, &stack_b);
			ft_printf("size_a:%d\n", ft_lstsize(stack_a));
			ft_printf("size_b:%d\n", ft_lstsize(stack_b));
			ft_printf("a1:%d\n", stack_a->content);
			ft_printf("a2:%d\n", stack_a->next->content);
			ft_printf("b1:%d\n", stack_b->content);
		}
		else if (ft_lstsize(stack_a) > 3)
		{
			target_node(&stack_a, &stack_b);
		}
	}
	else
		ft_printf("numbers are in ascending order");
}
