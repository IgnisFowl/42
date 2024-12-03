/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:45:44 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/27 13:33:42 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_how_many_digits(int n)
{
	int				i;
	unsigned int	num;

	i = 0;
	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		i = 1;
		num = -n;
	}
	else
		num = n;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_handle_int_padding(t_print *tab, int length)
{
	int	padding;

	padding = tab->wdt - length;
	if (padding > 0)
	{
		if (tab->zero && !tab->pnt)
		{
			while (padding-- > 0)
				tab->tl += write(1, "0", 1);
		}
		else
		{
			while (padding-- > 0)
				tab->tl += write(1, " ", 1);
		}
	}
}

static int	ft_handle_int_prefix(t_print *tab, int num, int length)
{
	int	total_length;

	if (tab->pnt && tab->prc > length)
		total_length = tab->prc;
	else
		total_length = length;
	if (num < 0 || tab->sign || tab->sp)
		total_length++;
	if (!tab->dash)
		ft_handle_int_padding(tab, total_length);
	if (num < 0)
		tab->tl += write(1, "-", 1);
	else if (tab->sign)
		tab->tl += write(1, "+", 1);
	else if (tab->sp)
		tab->tl += write(1, " ", 1);
	while (tab->pnt && tab->prc > length++)
		tab->tl += write(1, "0", 1);
	return (total_length);
}

void	ft_print_int(t_print *tab, int num)
{
	int	length;
	int	total_length;

	if (num == INT_MIN)
	{
		tab->tl += write(1, "-2147483648", 11);
		return ;
	}
	if (tab->pnt && tab->prc == 0 && num == 0)
	{
		ft_handle_int_padding(tab, 0);
		return ;
	}
	length = ft_how_many_digits(num);
	total_length = ft_handle_int_prefix(tab, num, length);
	if (num < 0)
		num = -num;
	ft_putnbr_fd(num, 1);
	tab->tl += ft_how_many_digits(num);
	if (tab->dash)
		ft_handle_int_padding(tab, total_length);
}
