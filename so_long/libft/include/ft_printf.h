/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:43:14 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/26 17:45:34 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		perc;
	int		sp;
	int		hash;
}	t_print;

int		ft_printf(const char *format, ...);
int		ft_eval(t_print *tab, const char *format, size_t *i);
void	ft_handle_int_padding(t_print *tab, int length);
void	ft_print_int(t_print *tab, int num);
void	ft_print_uns(t_print *tab, unsigned int arg);
void	ft_print_hex(t_print *tab, unsigned int num, int upper);
void	ft_print_ptr(t_print *tab, void *ptr);
void	ft_print_char(t_print *tab, char c);
void	ft_print_str(t_print *tab, char *str);
void	ft_putnbr_hex(unsigned long num, int upper);
int		ft_how_many_digits_hex(unsigned long num);

#endif