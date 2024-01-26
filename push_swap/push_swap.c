/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/26 15:14:06 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_check(t_list **stack_a, t_list **stack_b)
{
	int		rb_i;
	int		ra_i;

	stack_init(*stack_a, *stack_b);
	rb_i = case_br(*stack_b);
	ra_i = case_ar(*stack_a, *stack_b);
	//apply rotation
	if ((get_min_cost(*stack_b)->m_po == 0 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 0)
		|| (get_min_cost(*stack_b)->m_po == 0 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 1)
		|| (get_min_cost(*stack_b)->m_po == 1 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 0)
		|| (get_min_cost(*stack_b)->m_po == 1 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 1))
	{
		if (ra_i == rb_i)
			apply_rr(stack_a, stack_b, ra_i);
		else
		{
			apply_ra(stack_a, ra_i);
			apply_rb(stack_b, rb_i);
		}
		pa(stack_a, stack_b);
	}
	else if ((get_min_cost(*stack_b)->m_po == 0 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 2)
		|| (get_min_cost(*stack_b)->m_po == 1 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 2))
	{
		apply_rra(stack_a, ra_i);
		apply_rb(stack_b, rb_i);
		pa(stack_a, stack_b);
	}
	else if ((get_min_cost(*stack_b)->m_po == 2 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 0)
		|| (get_min_cost(*stack_b)->m_po == 2 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 1))
	{
		apply_ra(stack_a, ra_i);
		apply_rrb(stack_b, rb_i);
		pa(stack_a, stack_b);
	}
	else if (get_min_cost(*stack_b)->m_po == 2 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 2)
	{
		if (ra_i == rb_i)
			apply_rrr(stack_a, stack_b, ra_i);
		else
		{
			apply_rra(stack_a, ra_i);
			apply_rrb(stack_b, rb_i);
		}
		pa(stack_a, stack_b);
	}
}

void	push_b_thr_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		pb(stack_b, stack_a);
	if (order_check(stack_a) == 0)
		sort_thr(stack_a);
	while (*stack_b)
		stack_check(stack_a, stack_b);
	index_init(*stack_a);
	if (get_min(*stack_a)->m_po == 1)
		apply_ra(stack_a, get_min(*stack_a)->index);
	else
		apply_rra(stack_a, get_min(*stack_a)->index);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		push_b_thr_a(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_thr(stack_a);
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = malloc(sizeof (t_list));
	stack_b = malloc(sizeof (t_list));
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		stacking(&stack_a, ac, av);
	if (order_check(&stack_a) == 0)
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_thr(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
	ft_printf("a_%d:\t", ft_lstsize(stack_a));
	while (stack_a)
	{
		ft_printf("%d\t", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	if (ft_lstsize(stack_b) != 0)
	{
		ft_printf("b_%d:\t", ft_lstsize(stack_b));
		while (stack_b)
		{
			ft_printf("%d\t", stack_b->content);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}
