/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:44:42 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/26 17:12:11 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_print	*ft_init_flags(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	tab->hash = 0;
	return (tab);
}

static void	ft_parse_flags(t_print *tab, const char *format, size_t *i)
{
	while (format[*i] && ft_strchr("-0# +", format[*i]))
	{
		if (format[*i] == '-')
			tab->dash = 1;
		else if (format[*i] == '0')
			tab->zero = 1;
		else if (format[*i] == '#')
			tab->hash = 1;
		else if (format[*i] == '+')
			tab->sign = 1;
		else if (format[*i] == ' ')
			tab->sp = 1;
		if (tab->dash)
			tab->zero = 0;
		if (tab->sign)
			tab->sp = 0;
		(*i)++;
	}
}

static void	ft_parse_wdt(t_print *tab, const char *format, size_t *i)
{
	if (ft_isdigit(format[*i]))
	{
		tab->wdt = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	if (tab->wdt < 0)
	{
		tab->dash = 1;
		tab->wdt = -tab->wdt;
	}
}

static void	ft_parse_prc(t_print *tab, const char *format, size_t *i)
{
	if (format[*i] == '.')
	{
		tab->pnt = 1;
		(*i)++;
		if (ft_isdigit(format[*i]))
		{
			tab->prc = ft_atoi(&format[*i]);
			while (ft_isdigit(format[*i]))
				(*i)++;
		}
		else
		{
			tab->prc = 0;
			while (format[*i] && !ft_isdigit(format[*i]) \
			&& !ft_strchr("cspdiuxX%", format[*i]))
				(*i)++;
		}
	}
}

int	ft_eval(t_print *tab, const char *format, size_t *i)
{
	ft_init_flags(tab);
	ft_parse_flags(tab, format, i);
	ft_parse_wdt(tab, format, i);
	ft_parse_prc(tab, format, i);
	if (format[*i] == 'c')
		ft_print_char(tab, ((char)va_arg(tab->args, int)));
	else if (format[*i] == 's')
		ft_print_str(tab, (va_arg(tab->args, char *)));
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_print_int(tab, (va_arg(tab->args, int)));
	else if (format[*i] == 'u')
		ft_print_uns(tab, (va_arg(tab->args, unsigned int)));
	else if (format[*i] == 'p')
		ft_print_ptr(tab, (va_arg(tab->args, void *)));
	else if (format[*i] == 'x')
		ft_print_hex(tab, (va_arg(tab->args, unsigned int)), 0);
	else if (format[*i] == 'X')
		ft_print_hex(tab, (va_arg(tab->args, unsigned int)), 1);
	else if (format[*i] == '%')
		tab->tl += write(1, "%", 1);
	else
		return (*i);
	return (*i + 1);
}
