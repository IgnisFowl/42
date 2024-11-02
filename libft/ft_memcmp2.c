/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:03:57 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/09 14:16:10 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;

	src1 = (const unsigned char *)s1;
	src2 = (const unsigned char *)s2;
    if (n > 0)
    {
        while (n--)
        {
            if (*src1 != *src2)
                return (*src1 - *src2);
            src1++;
            src2++;
        }
    }
	return (0);
}
