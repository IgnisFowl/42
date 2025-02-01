/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:32:00 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/02/01 10:25:33 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_binary(int i)
{
	int	binary;

	binary = 1;
	while (i > 1)
	{
		i = i / 2;
		binary++;
	}
	return (binary);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	bit_shift;
	int	index_count;
	int	i;

	index_count = index_binary(len - 1);
	bit_shift = 0;
	while (bit_shift < index_count)
	{
		i = len;
		while (i != 0)
		{
			if (!(((*stack_a)->index >> bit_shift) & 1))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i--;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit_shift++;
	}
}
