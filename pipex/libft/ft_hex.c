/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:45:15 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/27 13:40:10 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_how_many_digits_hex(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

static void	ft_handle_hex_padding(t_print *tab, int length, int prefix_len)
{
	int	padding;

	padding = tab->wdt - length - prefix_len;
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

void	ft_putnbr_hex(unsigned long num, int upper)
{
	if (num >= 16)
		ft_putnbr_hex(num / 16, upper);
	if (upper)
		write(1, &"0123456789ABCDEF"[num % 16], 1);
	else
		write(1, &"0123456789abcdef"[num % 16], 1);
}

static void	ft_print_prefix(unsigned int n, t_print *tab, int upper)
{
	if (tab->hash && n != 0)
	{
		if (upper)
			tab->tl += write(1, "0X", 2);
		else
			tab->tl += write(1, "0x", 2);
	}
}

void	ft_print_hex(t_print *tab, unsigned int num, int upper)
{
	int	length;
	int	prefix_len;
	int	temp_prc;

	prefix_len = 0;
	if (tab->hash && num != 0)
		prefix_len = 2;
	if (num == 0 && tab->pnt && tab->prc == 0)
	{
		ft_handle_hex_padding(tab, 0, prefix_len);
		return ;
	}
	length = ft_how_many_digits_hex(num);
	temp_prc = tab->prc;
	if (tab->pnt && tab->prc > length)
		length = tab->prc;
	if ((tab->zero && !tab->pnt) || !tab->dash)
		ft_handle_hex_padding(tab, length + prefix_len, prefix_len);
	ft_print_prefix(num, tab, upper);
	while (tab->pnt && temp_prc-- > ft_how_many_digits_hex(num))
		tab->tl += write(1, "0", 1);
	ft_putnbr_hex(num, upper);
	tab->tl += length;
	if (tab->dash)
		ft_handle_hex_padding(tab, length, prefix_len);
}
