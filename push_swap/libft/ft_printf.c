/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:44:25 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/22 17:27:13 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_handle_char_or_format(t_print *tab, const char *format, \
size_t i, int *ret)
{
	if (format[i] == '%')
	{
		i++;
		i = ft_eval(tab, format, &i);
		*ret += tab->tl;
	}
	else
	{
		*ret += write(1, &format[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	va_start(tab->args, format);
	while (format[i])
		i = ft_handle_char_or_format(tab, format, i, &ret);
	va_end(tab->args);
	free(tab);
	return (ret);
}
