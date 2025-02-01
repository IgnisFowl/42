/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:47:58 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/01/28 14:57:57 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->number < min->number))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	if (!stack || !*stack)
		error();
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

int	get_min(t_stack *head)
{
	t_stack	*temp;
	int		min;

	min = head->number;
	temp = head;
	while (temp)
	{
		if (temp->number < min)
			min = temp->number;
		temp = temp->next;
	}
	return (min);
}

int	get_max(t_stack *head)
{
	t_stack	*temp;
	int		max;

	max = head->number;
	temp = head;
	while (temp)
	{
		if (temp->number < max)
			max = temp->number;
		temp = temp->next;
	}
	return (max);
}

void	move_to_top(int min, t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->number != min)
		temp = temp->next;
	if (temp->next == NULL)
	{
		rra(stack);
		return ;
	}
	while ((*stack)->number != min)
		ra(stack);
}
