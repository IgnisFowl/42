/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:24:22 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/31 11:15:43 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;
	char	search;
	size_t	i;

	search = (char)c;
	temp = (char *)s;
	i = 0;
	while (*s)
	{
		if (*s == search)
			return (temp + i);
		s++;
		i++;
	}
	if (*s == search)
		return (temp + i);
	return (0);
}
