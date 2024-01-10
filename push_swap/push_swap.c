/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/10 18:10:29 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *stack, int content)
{
	int	i;

	i = 0;
	while (stack->content != content)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

int	get_content_index_b(t_list *stack_b, int content)
{
	int		i;
	t_list	*temp;

	i = 1;
	if (content > stack_b->content && content < ft_lstlast(stack_b)->content)
		i = 0;
	else if (content > get_max(&stack_b)->content
		|| content < get_min(&stack_b)->content)
		i = get_index(stack_b, get_max(&stack_b)->content);
	else
	{
		temp = stack_b->next;
		while (content > stack_b->content || content < temp->content)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	case_rrarrb(t_list *stack_a, t_list *stack_b, int content)
{
	int	i;

	i = 0;
	if (get_content_index_b(stack_b, content) != 0)
		i = ft_lstsize(stack_b) - get_content_index_b(stack_b, content);
	if (i < (ft_lstsize(stack_a) - get_index(stack_a, content))
		&& get_index(stack_a, content) != 0)
		i = ft_lstsize(stack_a) - get_index(stack_a, content);
	return (i);
}

int	case_rarb(t_list *stack_a, t_list *stack_b, int content)
{
	int	i;

	i = 0;
	i = get_content_index_b(stack_b, content);
	if (i < get_index(stack_a, content))
		i = get_index(stack_a, content);
	return (i);
}

int	case_rrarb(t_list *stack_a, t_list *stack_b, int content)
{
	int	i;

	i = 0;
	if (get_index(stack_a, content))
		i = ft_lstsize(stack_a) - get_index(stack_a, content);
	i += get_content_index_b(stack_b, content);
	return (i);
}

int	case_rarrb(t_list *stack_a, t_list *stack_b, int content)
{
	int	i;

	i = 0;
	if (get_content_index_b(stack_b, content))
		i = ft_lstsize(stack_b) - get_content_index_b(stack_b, content);
	i += get_index(stack_a, content);
	return (i);
}

int	ft_rarb(t_list **stack_a, t_list **stack_b, int content)
{
	// to be continued..
	ft_printf("Hello\n");
	while ((*stack_a)->content != content
		&& get_content_index_b(*stack_b, content) > 0)
		rr(stack_a, stack_b);
	while ((*stack_a)->content != content)
		ra(stack_a);
	while (get_content_index_b(*stack_b, content) > 0)
		rb(stack_b);
	pb(stack_b, stack_a);
	return (-1);
}

int	ft_rrarrb(t_list **stack_a, t_list **stack_b, int content)
{
	while ((*stack_a)->content != content
		&& get_content_index_b(*stack_b, content))
		rrr(stack_a, stack_b);
	while ((*stack_a)->content != content)
		rra(stack_a);
	while (get_content_index_b(*stack_b, content) > 0)
		rrb(stack_b);
	pb(stack_b, stack_a);
	return (-1);
}

int	ft_rrarb(t_list **stack_a, t_list **stack_b, int content)
{
	while ((*stack_a)->content != content
		&& get_content_index_b(*stack_b, content))
		rra(stack_a);
	while (get_content_index_b(*stack_b, content) > 0)
		rb(stack_b);
	pb(stack_b, stack_a);
	return (-1);
}

int	ft_rarrb(t_list **stack_a, t_list **stack_b, int content)
{
	while ((*stack_a)->content != content
		&& get_content_index_b(*stack_b, content))
		ra(stack_a);
	while (get_content_index_b(*stack_b, content) > 0)
		rrb(stack_b);
	pb(stack_b, stack_a);
	return (-1);
}

int	rot_ab(t_list *stack_a, t_list *stack_b)
{
	int		i;
	t_list	*temp;

	temp = stack_a;
	i = 1;
	while (temp)
	{
		if (i > case_rarb(stack_a, stack_b, temp->content))
			i = case_rarb(stack_a, stack_b, temp->content);
		if (i > case_rrarrb(stack_a, stack_b, temp->content))
			i = case_rrarrb(stack_a, stack_b, temp->content);
		if (i > case_rarrb(stack_a, stack_b, temp->content))
			i = case_rarrb(stack_a, stack_b, temp->content);
		if (i > case_rrarb(stack_a, stack_b, temp->content))
			i = case_rrarb(stack_a, stack_b, temp->content);
		temp = temp ->next;
	}
	return (i);
}

void	push_b_thr_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*temp;

	while (ft_lstsize(*stack_a) > 3)
	{
		temp = *stack_a;
		i = rot_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb(*stack_a, *stack_b, temp->content))
				i = ft_rarb(stack_a, stack_b, temp->content);
			else if (i == case_rrarrb(*stack_a, *stack_b, temp->content))
				i = ft_rrarrb(stack_a, stack_b, temp->content);
			else if (i == case_rarrb(*stack_a, *stack_b, temp->content))
				i = ft_rarrb(stack_a, stack_b, temp->content);
			else if (i == case_rrarb(*stack_a, *stack_b, temp->content))
				i = ft_rrarb(stack_a, stack_b, temp->content);
		}
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
