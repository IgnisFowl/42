/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:14:34 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 11:07:42 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	**populate_map(char **map, int fd, int lines)
{
	int		i;
	char	*line;

	i = 0;
	while (i < lines)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_map(map);
			close(fd);
			return (NULL);
		}
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	return (map);
}

static int	check_map(char **map)
{
	if (!is_rectangular(map) || !is_enclosed(map) || \
	!is_map_valid(map) || !validate_elements(map))
	{
		free_map(map);
		return (0);
	}
	else
		return (1);
}

char	**read_map(char *filename)
{
	int		fd;
	int		lines;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = count_lines(filename);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map || lines <= 0)
	{
		close(fd);
		return (NULL);
	}
	populate_map(map, fd, lines);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	if (check_map(map) == 0)
		map = NULL;
	close(fd);
	return (map);
}
