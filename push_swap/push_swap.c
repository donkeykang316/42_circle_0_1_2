/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/21 20:56:02 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack_a, t_list *stack_b)
{
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

void	index_init(t_list *stack)
{
	int	i;
	int	median;
	int	temp;

	i = 0;
	if (ft_lstsize(stack) > 4)
	{
		median = ft_lstsize(stack) / 2;
		temp = median;
		while (median--)
		{
			stack->index = i;
			stack->m_po = 1;
			i++;
			stack = stack->next;
		}
		while (temp)
		{
			stack->index = temp;
			stack->m_po = 2;
			temp--;
			stack = stack->next;
		}
	}
	else
	{
		median = ft_lstsize(stack);
		while (median--)
		{
			stack->index = i;
			stack->m_po = 1;
			i++;
			stack = stack->next;
		}
	}
}

t_list	*target_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = stack_a;
	temp_b = stack_b;
	while ((temp_b->content > temp_a->content) && temp_a)
	{
		if (temp_a == ft_lstlast(temp_a))
			return (temp_a);
		temp_a = temp_a->next;
	}
	return (temp_a);
}

void	push_cost(t_list *stack_a, t_list *stack_b)
{
	while (stack_b)
	{
		stack_b->cost = stack_b->index + target_node(stack_a, stack_b)->index;
		stack_b = stack_b->next;
	}
}

t_list	*get_min_cost(t_list *stack)
{
	t_list	*min;
	t_list	*min_node;
	int		min_cost;

	min = stack;
	min_node = stack;
	min_cost = min->cost;
	while (min)
	{
		if (min_cost > min->cost)
			min_cost = min->cost;
		min = min->next;
	}
	while (min_node)
	{
		if (min_node->cost == min_cost)
			return (min_node);
		else
			min_node = min_node->next;
	}
	return (0);
}

void	stack_init(t_list *stack_a, t_list *stack_b)
{
	index_init(stack_a);
	index_init(stack_b);
	push_cost(stack_a, stack_b);
}

int	case_rb(t_list *stack_b)
{
	int	i;

	i = get_min_cost(stack_b)->index;
	return (i);
}

int	case_rrb(t_list *stack_b)
{
	int	i;

	i = get_min_cost(stack_b)->index;
	return (i);
}

int	case_ra(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = target_node(stack_a, get_min_cost(stack_b))->index;
	return (i);
}

int	case_rra(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = target_node(stack_a, get_min_cost(stack_b))->index;
	return (i);
}

void	apply_ra(t_list **stack_a, int i)
{
	while (i--)
		ra(stack_a);
}

void	apply_rb(t_list **stack_b, int i)
{
	while (i--)
		rb(stack_b);
}

void	apply_rra(t_list **stack_a, int i)
{
	while (i--)
		rra(stack_a);
}

void	apply_rrb(t_list **stack_b, int i)
{
	while (i--)
		rrb(stack_b);
}

void	stack_check(t_list **stack_a, t_list **stack_b)
{
	int		rb_i;
	int		ra_i;

	stack_init(*stack_a, *stack_b);
	if (get_min_cost(*stack_b)->m_po == 1)
	{
		rb_i = case_rb(*stack_b);
	}
	else if (get_min_cost(*stack_b)->m_po == 2)
	{
		rb_i = case_rrb(*stack_b);
	}
	else
		rb_i = case_rrb(*stack_b);
	if (target_node(*stack_a, get_min_cost(*stack_b))->m_po == 1)
	{
		if (target_node(*stack_a, get_min_cost(*stack_b))->content == ft_lstlast(*stack_a)->content
			&& (get_min_cost(*stack_b)->content > ft_lstlast(*stack_a)->content
			|| get_min_cost(*stack_b)->content < ft_lstlast(*stack_a)->content))
				ra_i = 0;
		else
			ra_i = case_ra(*stack_a, *stack_b);
	}
	else if (target_node(*stack_a, get_min_cost(*stack_b))->m_po == 2)
	{
		if (target_node(*stack_a, get_min_cost(*stack_b))->content == ft_lstlast(*stack_a)->content
			&& get_min_cost(*stack_b)->content > ft_lstlast(*stack_a)->content)
			ra_i = 0;
		else if (target_node(*stack_a, get_min_cost(*stack_b))->content == ft_lstlast(*stack_a)->content
			&& get_min_cost(*stack_b)->content < ft_lstlast(*stack_a)->content)
			ra_i = 1;
		else
			ra_i = case_rra(*stack_a, *stack_b);
	}
	else
	{
		if (target_node(*stack_a, get_min_cost(*stack_b))->content == ft_lstlast(*stack_a)->content
			&& (get_min_cost(*stack_b)->content > ft_lstlast(*stack_a)->content
			|| get_min_cost(*stack_b)->content < ft_lstlast(*stack_a)->content))
			ra_i = 0;
		else
			ra_i = case_rra(*stack_a, *stack_b);
	}
	//apply rotation
	if (get_min_cost(*stack_b)->m_po == 1 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 1)
	{
		if (get_min_cost(*stack_b)->content > ft_lstlast(*stack_a)->content)
		{
			apply_ra(stack_a, ra_i);
			apply_rb(stack_b, rb_i);
			pa(stack_a, stack_b);
			apply_ra(stack_a, ra_i + 1);
		}
		else if (get_min_cost(*stack_b)->content < ft_lstlast(*stack_a)->content)
		{
			apply_rra(stack_a, ra_i);
			apply_rb(stack_b, rb_i);
			pa(stack_a, stack_b);
			apply_ra(stack_a, ra_i);
		}
		else
		{
			apply_ra(stack_a, ra_i);
			apply_rb(stack_b, rb_i);
			pa(stack_a, stack_b);
			apply_rra(stack_a, ra_i);
		}
		print_stack(*stack_a, *stack_b);
	}
	else if (get_min_cost(*stack_b)->m_po == 2 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 2)
	{
		apply_rra(stack_a, ra_i);
		apply_rrb(stack_b, rb_i);
		pa(stack_a, stack_b);
		apply_ra(stack_a, ra_i);
		print_stack(*stack_a, *stack_b);
	}
	else if (get_min_cost(*stack_b)->m_po == 1 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 2)
	{
		if (get_min_cost(*stack_b)->content > ft_lstlast(*stack_a)->content)
		{
			apply_rra(stack_a, ra_i);
			apply_rb(stack_b, rb_i);
			pa(stack_a, stack_b);
			apply_ra(stack_a, ra_i + 1);
		}
		else if (get_min_cost(*stack_b)->content < ft_lstlast(*stack_a)->content)
		{
			apply_rra(stack_a, ra_i);
			apply_rb(stack_b, rb_i);
			pa(stack_a, stack_b);
			apply_ra(stack_a, ra_i + 1);
		}
		else
		{
			apply_rra(stack_a, ra_i);
			apply_rb(stack_b, rb_i);
			pa(stack_a, stack_b);
			apply_ra(stack_a, ra_i);
		}
		print_stack(*stack_a, *stack_b);
	}
	else if (get_min_cost(*stack_b)->m_po == 2 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 1)
	{
		apply_ra(stack_a, ra_i);
		apply_rrb(stack_b, rb_i);
		pa(stack_a, stack_b);
		apply_rra(stack_a, ra_i);
		print_stack(*stack_a, *stack_b);
	}
	else if (get_min_cost(*stack_b)->m_po == 1 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 0)
	{
		if (get_min_cost(*stack_b)->content > ft_lstlast(*stack_a)->content)
		{
			apply_ra(stack_a, ra_i);
			apply_rrb(stack_b, rb_i);
			pa(stack_a, stack_b);
			apply_ra(stack_a, ra_i + 1);
		}
		else if (get_min_cost(*stack_b)->content < ft_lstlast(*stack_a)->content)
		{
			apply_rra(stack_a, ra_i + 1);
			apply_rrb(stack_b, rb_i);
			pa(stack_a, stack_b);
			apply_ra(stack_a, ra_i + 2);
		}
		else
		{
			apply_ra(stack_a, ra_i);
			apply_rrb(stack_b, rb_i);
			pa(stack_a, stack_b);
			apply_rra(stack_a, ra_i);
		}
		print_stack(*stack_a, *stack_b);
	}
	else if (get_min_cost(*stack_b)->m_po == 2 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 0)
	{
		apply_ra(stack_a, ra_i);
		apply_rrb(stack_b, rb_i);
		pa(stack_a, stack_b);
		apply_rra(stack_a, ra_i);
		print_stack(*stack_a, *stack_b);
	}
	else if (get_min_cost(*stack_b)->m_po == 0 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 1)
	{
		//find issue later
		ft_printf("Oerror:%d\n", target_node(*stack_a, get_min_cost(*stack_b))->content);
		ft_printf("Oerror:%d\n", ra_i);
		apply_ra(stack_a, ra_i);
		apply_rrb(stack_b, rb_i);
		pa(stack_a, stack_b);
		apply_rra(stack_a, ra_i);
		print_stack(*stack_a, *stack_b);
	}
	else if (get_min_cost(*stack_b)->m_po == 0 && target_node(*stack_a, get_min_cost(*stack_b))->m_po == 2)
	{
		apply_ra(stack_a, ra_i);
		apply_rrb(stack_b, rb_i);
		pa(stack_a, stack_b);
		apply_rra(stack_a, ra_i);
		print_stack(*stack_a, *stack_b);
	}
}

void	push_b_thr_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		pb(stack_b, stack_a);
	if (order_check(stack_a) == 0)
		sort_thr(stack_a);
	print_stack(*stack_a, *stack_b);
	while (*stack_b)
	{
		if (ft_lstsize(*stack_b) == 1)
		{
			stack_check(stack_a, stack_b);
			*stack_b = NULL;
			break ;
		}
		stack_check(stack_a, stack_b);
		//print_stack(*stack_a, *stack_b);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		pb(stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		pb(stack_b, stack_a);
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
		{
			sort_stack(&stack_a, &stack_b);
		}
	}
	else
		ft_printf("numbers are in ascending order");

	ft_printf("size_a:%d\n", ft_lstsize(stack_a));
	ft_printf("size_b:%d\n", ft_lstsize(stack_b));
	ft_printf("a:\t");
	while (stack_a)
	{
		ft_printf("%d\t", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	if (ft_lstsize(stack_b) != 0)
	{
		ft_printf("b:\t");
		while (stack_b)
		{
			ft_printf("%d\t", stack_b->content);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}
