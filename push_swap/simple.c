/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:32:00 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/02/01 15:33:08 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	if (head->index > head->next->index && \
	head->index > head->next->next->index)
	{
		ra(stack);
		if (!is_sorted(stack))
			sa(stack);
	}
	else if (head->next->index > head->index && \
	head->next->index > head->next->next->index)
	{
		rra(stack);
		if (!is_sorted(stack))
			sa(stack);
	}
	else
	{
		if (!is_sorted(stack))
			sa(stack);
	}
}

static void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	move_to_top(get_min(*stack_a), stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	move_to_top(get_min(*stack_a), stack_a);
	pb(stack_a, stack_b);
	move_to_top(get_min(*stack_a), stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_lstsize(*stack_a);
	if (is_sorted(stack_a) || size < 2)
		return ;
	if (size == 2)
		sa(stack_a);
	if (size == 3)
		sort_3(stack_a);
	if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
