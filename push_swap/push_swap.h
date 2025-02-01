/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:49:52 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/02/01 10:21:58 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# include "libft/include/ft_printf.h"
# include "libft/include/libft.h"

typedef struct s_stack {
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	error(void);
void	ft_free(char **str);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack **stack);
int		check_args(int argc, char **argv);
void	index_stack(t_stack **stack);
int		get_min(t_stack *head);
int		get_max(t_stack *head);
void	move_to_top(int min, t_stack **stack);
long	ft_atol(const char *str);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_stack_lstnew(int number);
void	ft_stack_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stack_lstlast(t_stack *head);
void	ft_stack_lstadd_back(t_stack **stack, t_stack *new);
int		ft_stack_lstsize(t_stack *head);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int len);

#endif