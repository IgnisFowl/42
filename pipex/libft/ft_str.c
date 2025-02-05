/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:46:09 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/26 17:29:23 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_c_padding(t_print *tab, int length)
{
	int	padding;

	padding = tab->wdt - length;
	if (padding > 0)
	{
		while (padding-- > 0)
		{
			if (tab->zero && !tab->dash)
				tab->tl += write(1, "0", 1);
			else
				tab->tl += write(1, " ", 1);
		}
	}
}

static void	ft_handle_s_padding(t_print *tab, int length)
{
	int	padding;

	if (tab->pnt && tab->prc < length)
		length = tab->prc;
	padding = tab->wdt - length;
	if (padding > 0)
	{
		while (padding-- > 0)
		{
			if (tab->zero && !tab->dash)
				tab->tl += write(1, "0", 1);
			else
				tab->tl += write(1, " ", 1);
		}
	}
}

void	ft_print_char(t_print *tab, char c)
{
	if (tab->dash)
	{
		tab->tl += write(1, &c, 1);
		if (tab->wdt > 0)
			ft_handle_c_padding(tab, 1);
	}
	else
	{
		if (tab->wdt > 0)
			ft_handle_c_padding(tab, 1);
		tab->tl += write(1, &c, 1);
	}
}

void	ft_print_str(t_print *tab, char *str)
{
	int		length;
	int		output_length;

	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (tab->pnt && tab->prc < length)
		output_length = tab->prc;
	else
		output_length = length;
	if (!tab->dash)
		ft_handle_s_padding(tab, output_length);
	tab->tl += write(1, str, output_length);
	if (tab->dash)
		ft_handle_s_padding(tab, output_length);
}
