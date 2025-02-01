/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:09:41 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/01/28 12:17:03 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_lstnew(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = number;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_stack_lstadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_stack_lstlast(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_stack_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (*stack)
	{
		temp = ft_stack_lstlast(*stack);
		temp->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	ft_stack_lstsize(t_stack *head)
{
	size_t	i;
	t_stack	*temp;

	temp = head;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
