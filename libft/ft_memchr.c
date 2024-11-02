/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:46:31 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/09 14:20:51 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		ch;

	src = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*src == ch)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
