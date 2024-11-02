/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:55:33 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/15 13:28:14 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static int	ft_howmanydigits(int n)
{
	int				i;
	unsigned int	num;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		num = -n;
	}
	else
		num = n;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*result;
	unsigned int	num;

	len = ft_howmanydigits(n);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		num = -n;
	}
	else
		num = n;
	result[len] = '\0';
	while (num != 0)
	{
		result[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n == 0)
		result[0] = '0';
	return (result);
}
