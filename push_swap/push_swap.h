/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:30:58 by someng            #+#    #+#             */
/*   Updated: 2024/01/22 17:46:44 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <stdlib.h>
# include <ctype.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				cost;
	int				m_po;		
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		main(int ac, char **av);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		order_check(t_list **stack);
t_list	*get_max(t_list *stack);
t_list	*get_min(t_list *stack);
void	stacking(t_list **stack_a, int ac, char **av);
void	push(t_list **stack, t_list **node);
void	swap(t_list **stack);
void	rotat(t_list **stack);
void	rev_rotat(t_list **stack);
void	sort_thr(t_list **stack_a);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	index_init(t_list *stack);
t_list	*target_node(t_list *stack_a, t_list *stack_b);
void	push_cost(t_list *stack_a, t_list *stack_b);
t_list	*get_min_cost(t_list *stack);
void	stack_init(t_list *stack_a, t_list *stack_b);
int		case_rb(t_list *stack_b);
int		case_rrb(t_list *stack_b);
int		case_ra(t_list *stack_a, t_list *stack_b);
int		case_rra(t_list *stack_a, t_list *stack_b);
void	apply_ra(t_list **stack_a, int i);
void	apply_rb(t_list **stack_b, int i);
void	apply_rra(t_list **stack_a, int i);
void	apply_rrb(t_list **stack_b, int i);
void	apply_rr(t_list **stack_a, t_list **stack_b, int i);
void	apply_rrr(t_list **stack_a, t_list **stack_b, int i);

#endif
