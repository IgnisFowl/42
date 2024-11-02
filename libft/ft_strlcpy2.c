/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:25:08 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/22 16:41:16 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include "libft.h"

size_t	ft_strlen(const char *c);

void	*ft_memcpy(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_len;

	s_len = ft_strlen(src);
    if (!src)
        return (0);
	if (size == 0)
		return (s_len);
	if (s_len < size)
		ft_memcpy(dst, src, s_len + 1);
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (s_len);
}
