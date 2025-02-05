/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:58:02 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/01/16 14:21:55 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	if (paths)
	{
		while (paths[i])
			free(paths[i++]);
		free(paths);
	}
}

static char	**get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		error("Memory allocation for get_path failed");
	return (paths);
}

static char	*create_full_path(char *path, char *cmd)
{
	char	*part_path;
	char	*full_path;

	part_path = ft_strjoin(path, "/");
	if (!part_path)
		return (NULL);
	full_path = ft_strjoin(part_path, cmd);
	free(part_path);
	return (full_path);
}

static char	*check_path(char *cmd, char **paths, int i)
{
	char	*path;

	path = create_full_path(paths[i], cmd);
	if (!path)
		return (NULL);
	if (access(path, F_OK | X_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	paths = get_paths(envp);
	while (paths[i])
	{
		path = check_path(cmd, paths, i);
		if (path)
		{
			free_paths(paths);
			return (path);
		}
		i++;
	}
	free_paths(paths);
	return (NULL);
}
