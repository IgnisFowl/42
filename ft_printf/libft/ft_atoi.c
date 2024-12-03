/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:04:04 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/28 12:01:24 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\r' || c == '\f' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	j;
	int		sign;
	long	result;

	i = 0;
	j = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	while ((nptr[i] == '-' || nptr[i] == '+') && j == 0)
	{
		if (nptr[i] == '-' )
			sign *= -1;
		j = 1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
