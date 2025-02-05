/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:48:32 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/26 17:56:40 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_ptr_padding(t_print *tab, int length)
{
	int	padding;

	padding = tab->wdt - length;
	if (tab->hash && length > 0)
		padding -= 2;
	if (padding > 0 && !tab->dash)
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
	if (padding > 0 && tab->dash)
	{
		while (padding-- > 0)
			tab->tl += write(1, " ", 1);
	}
}

static void	ft_print_null_ptr(t_print *tab)
{
	int	length;

	if (tab->pnt && tab->prc == 0)
		length = 0;
	else
		length = 5;
	if (!tab->dash)
		ft_handle_ptr_padding(tab, length);
	if (!(tab->pnt && tab->prc == 0))
		tab->tl += write(1, "(nil)", 5);
	if (tab->dash)
		ft_handle_ptr_padding(tab, length);
}

void	ft_print_ptr(t_print *tab, void *ptr)
{
	unsigned long	num;
	int				length;

	if (!ptr)
	{
		ft_print_null_ptr(tab);
		return ;
	}
	num = (uintptr_t)ptr;
	length = ft_how_many_digits_hex(num);
	if (tab->pnt && tab->prc > length)
		length = tab->prc;
	length += 2;
	if (!tab->dash)
		ft_handle_ptr_padding(tab, (length));
	tab->tl += write(1, "0x", 2);
	while (tab->pnt && tab->prc-- > ft_how_many_digits_hex(num))
		tab->tl += write(1, "0", 1);
	ft_putnbr_hex(num, 0);
	tab->tl += length - 2;
	if (tab->dash)
		ft_handle_ptr_padding(tab, length);
}	
