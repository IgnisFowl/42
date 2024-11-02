/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:25:25 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/16 17:28:02 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest || !src)
		return (NULL);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}
