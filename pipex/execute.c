/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:13:37 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/01/20 11:51:19 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

size_t	ft_countwords(const char *s, char c)
{
	size_t	i;
	int		in_quote;

	i = 0;
	in_quote = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '"')
			in_quote = !in_quote;
		if (!in_quote && *s == c)
			s++;
		if (*s != c)
		{
			i++;
			while (*s && (in_quote || *s != c))
			{
				if (*s == '\'' || *s == '"')
					in_quote = !in_quote;
				s++;
			}
		}
	}
	return (i);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = 0;
	cmd = ft_custom_split(argv, ' ');
	if (!cmd)
		error("Memory allocation for cmd failed");
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_paths(cmd);
		perror("Command not found");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_paths(cmd);
		perror("Command not found");
		exit(127);
	}
	free(path);
	free_paths(cmd);
}
