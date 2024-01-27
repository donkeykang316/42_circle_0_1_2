/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:41:32 by kaan              #+#    #+#             */
/*   Updated: 2024/01/27 17:30:47 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_check(t_list *stack)
{
	t_list	*count;

	if (stack == NULL)
		return (0);
	count = stack;
	while (count->next)
	{
		if (count->content <= count->next->content)
			count = count->next;
		else
			return (0);
	}
	return (1);
}

void	free_errors(t_list *stack)
{
	ft_free(&stack);
	ft_printf("Error\n");
	exit(1);
}

t_list	*stacking(t_list *stack_a, int ac, char **av)
{
	t_list	*new;
	int		i;

	i = 1;
	if (ac >= 2)
	{
		new = NULL;
		while (av[i])
		{
			if (error_check(av[i]))
				free_errors(stack_a);
			if (error_dup_check(stack_a, ft_atoi(av[i])))
				free_errors(stack_a);
			new = ft_lstnew(ft_atoi(av[i]));
			ft_lstadd_back(&stack_a, new);
			i++;
		}
	}
	return (stack_a);
}

void	temp_free(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

t_list	*string_process(char **av, t_list *stack_a)
{
	t_list	*new;
	char	**temp;
	int		i;

	i = 0;
	temp = av;
	temp = ft_split(av[1], ' ');
	while (temp[i])
	{
		if (error_check(temp[i]))
			free_errors(stack_a);
		if (error_dup_check(stack_a, ft_atoi(temp[i])))
			free_errors(stack_a);
		new = ft_lstnew(ft_atoi(temp[i]));
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	temp_free(temp);
	return (stack_a);
}
