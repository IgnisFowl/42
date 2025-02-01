/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:32:00 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/02/01 10:24:38 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->number > head->next->number)
			return (0);
		head = head->next;
	}
	return (1);
}

void	make_top(t_stack **stack, int length)
{
	t_stack	*head;
	int		temp;

	if (length == 0)
		return ;
	head = *stack;
	temp = ft_stack_lstsize(head) - length;
	if (length <= (ft_stack_lstsize(head)) / 2)
	{
		while (length > 0)
		{
			ra(stack);
			length--;
		}
	}
	else
	{
		while (temp > 0)
		{
			rra(stack);
			temp--;
		}
	}
}
