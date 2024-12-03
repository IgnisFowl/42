/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:55:54 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/27 17:48:51 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;
	char	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	str = (char *)ptr;
	while (total_size--)
		*str++ = '0';
	return (ptr);
}

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_free(char *buffer, char *buf)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!buffer && !buf)
		return (NULL);
	if (buffer)
		s1_len = ft_strlen(buffer);
	else
		s1_len = 0;
	if (buf)
		s2_len = ft_strlen(buf);
	else
		s2_len = 0;
	result = (char *)malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	if (buffer)
		ft_memcpy(result, buffer, s1_len);
	if (buf)
		ft_memcpy(result + s1_len, buf, s2_len);
	result[s1_len + s2_len] = '\0';
	free(buffer);
	return (result);
}
