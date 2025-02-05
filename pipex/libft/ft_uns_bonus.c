/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:46:36 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/26 16:08:41 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_how_many_digits_uns(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		length;

	length = ft_how_many_digits_uns(n);
	num = (char *)malloc(sizeof(char) * (length + 1));
	if (!num)
		return (0);
	num[length] = '\0';
	while (n != 0)
	{
		num[length - 1] = (n % 10) + 48;
		n = n / 10;
		length--;
	}
	return (num);
}

static void	ft_process_uns(t_print *tab, unsigned int n)
{
	char	*number;
	int		length;

	if (n == 0)
	{
		tab->tl += write(1, "0", 1);
		return ;
	}
	length = ft_how_many_digits_uns(n);
	number = ft_uitoa(n);
	if (!number)
		return ;
	tab->tl += write(1, number, length);
	free(number);
}

void	ft_print_uns(t_print *tab, unsigned int arg)
{
	int	length;
	int	output_length;

	if (tab->pnt && tab->prc == 0 && arg == 0)
	{
		ft_handle_int_padding(tab, 0);
		return ;
	}
	length = ft_how_many_digits_uns(arg);
	if (tab->pnt && tab->prc > length)
		output_length = tab->prc;
	else
		output_length = length;
	if (!tab->dash && tab->wdt > output_length)
		ft_handle_int_padding(tab, output_length);
	while (tab->pnt && tab->prc > length++)
		tab->tl += write(1, "0", 1);
	ft_process_uns(tab, arg);
	if (tab->dash && tab->wdt > output_length)
		ft_handle_int_padding(tab, output_length);
}
