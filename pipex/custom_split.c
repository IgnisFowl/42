/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:10:43 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/01/20 11:35:39 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	size_t	i;

	len = 0;
	i = 0;
	while (s[len] && (s[len] != c || s[len] == '\'' || s[len] == '"'))
	{
		if (s[len] == '\'' || s[len] == '"')
		{
			len++;
			continue ;
		}
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (*s && (*s != c || *s == '\'' || *s == '"'))
	{
		if (*s != '\'' && *s != '"')
			word[i++] = *s;
		s++;
	}
	return (word);
}

static size_t	skip_to_next_word(const char *s, char c, int *in_quote)
{
	size_t	i;

	i = 0;
	while (s[i] && (*in_quote || s[i] != c))
	{
		if (s[i] == '\'' || s[i] == '"')
			*in_quote = !(*in_quote);
		i++;
	}
	return (i);
}

static char	**ft_split_words(char **result, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		in_quote;

	i = 0;
	j = 0;
	in_quote = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '"')
			in_quote = !in_quote;
		if (!in_quote && s[i] == c)
			i++;
		else
		{
			result[j] = ft_allocate(&s[i], c);
			if (!result[j])
				return (ft_free_results(result, j));
			j++;
			i += skip_to_next_word(&s[i], c, &in_quote);
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_custom_split(char const *s, char c)
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
