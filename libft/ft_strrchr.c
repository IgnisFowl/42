/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:19:54 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/18 11:13:59 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*j;

	j = NULL;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			j = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (j);
}
