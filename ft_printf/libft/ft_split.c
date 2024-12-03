/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:51:17 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/28 11:57:04 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char	**ft_free_results(char **results, size_t count)
{
	while (count > 0)
		free(results[--count]);
	free(results);
	return (NULL);
}

static char	*ft_allocate(const char *s, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static char	**ft_split_words(char **result, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result[j] = ft_allocate(&s[i], c);
			if (!result[j])
				return (ft_free_results(result, j));
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**results;

	if (s == NULL)
		return (NULL);
	results = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!results)
		return (NULL);
	results = ft_split_words(results, s, c);
	return (results);
}
