/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:13:47 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 11:02:06 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_linelen(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			count++;
		i++;
	}
	return (count);
}

int	is_rectangular(char **map)
{
	int	i;
	int	len;
	int	len_2;

	i = 0;
	len = ft_linelen(map[0]);
	len_2 = ft_linelen(map[0]);
	while (map[i] != NULL)
	{
		len_2 = ft_linelen(map[i]);
		if (len_2 != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_enclosed(char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	j = 0;
	width = ft_linelen(map[0]);
	height = 0;
	while (map[height])
		height++;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	while (j < width)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	init_map(t_map *map_elem, char **map)
{
	int	i;
	int	j;

	init_map_ints(map_elem);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				map_elem->player++;
				map_elem->player_x = i;
				map_elem->player_y = j;
			}
			if (map[i][j] == 'E')
				map_elem->exits++;
			if (map[i][j] == 'C')
				map_elem->chest++;
			j++;
		}
		i++;
	}
}

int	validate_elements(char **map)
{
	int		result;
	t_map	map_elem;

	init_map(&map_elem, map);
	result = 0;
	if (map_elem.player == 1 && map_elem.exits == 1 && map_elem.chest > 0)
		result = 1;
	return (result);
}
