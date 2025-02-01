/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:22:12 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/01/28 12:19:17 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		temp_num;
	int		temp_ind;

	if (ft_stack_lstsize(*stack) < 2)
		return ;
	head = *stack;
	next = head->next;
	if (!head && !next)
		error();
	temp_num = head->number;
	head->number = next->number;
	next->number = temp_num;
	temp_ind = head->index;
	head->index = next->index;
	next->index = temp_ind;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_lstsize(*stack_a) < 2 || ft_stack_lstsize(*stack_b) < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
