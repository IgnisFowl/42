/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:44:20 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/16 14:51:52 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = (char *)malloc(ft_strlen(s) + 1);
	if (!result || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		result[j] = f(i, s[i]);
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
