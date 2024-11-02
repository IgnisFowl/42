/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:46:14 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/18 11:39:09 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

static char	*ft_isempty(void)
{
	char	*result;

	result = ((char *)malloc(1));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		result = ft_isempty();
	else
	{
		if (len > s_len - start)
			len = s_len - start;
		result = (char *)malloc(len + 1);
		if (result == NULL || !s)
			return (NULL);
		while (i < len)
		{
			result[i] = s[start + i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
