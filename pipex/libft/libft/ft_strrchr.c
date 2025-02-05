/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:19:54 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/31 11:30:23 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		j;
	char	*temp;
	char	search;

	temp = (char *)s;
	search = (char)c;
	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (s[i] == search)
			j = i;
		i++;
	}
	if (s[i] == search)
		return (temp + i);
	if (j < 0)
		return (NULL);
	else
		return (temp + j);
}
