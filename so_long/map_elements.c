/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:38:16 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 11:02:23 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_ints(t_map *map_elem)
{
	map_elem->player = 0;
	map_elem->exits = 0;
	map_elem->chest = 0;
	map_elem->player_x = -1;
	map_elem->player_y = -1;
}

static void	flood_fill(char **map, int x, int y, t_map *info)
{
	if (x < 0 || y < 0 || !map[x] || !map[x][y] || \
	map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'C')
		info->found_chest++;
	if (map[x][y] == 'E')
		info->exit_reachable = 1;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y, info);
	flood_fill(map, x - 1, y, info);
	flood_fill(map, x, y + 1, info);
	flood_fill(map, x, y - 1, info);
}

static int	copy_map(char **map, char ***map_copy)
{
	int	i;
	int	map_height;

	i = 0;
	map_height = 0;
	while (map[map_height])
		map_height++;
	*map_copy = malloc(sizeof(char *) * (map_height + 1));
	while (map[i])
	{
		(*map_copy)[i] = ft_strdup(map[i]);
		if (!(*map_copy)[i])
		{
			free_map(*map_copy);
			return (0);
		}
		i++;
	}
	(*map_copy)[i] = NULL;
	return (1);
}

int	is_map_valid(char **map)
{
	t_map	info;
	char	**map_copy;

	map_copy = NULL;
	init_map(&info, map);
	if (info.player != 1 || info.exits != 1 || info.chest < 1)
		return (0);
	if (!copy_map(map, &map_copy))
		return (0);
	info.found_chest = 0;
	info.exit_reachable = 0;
	flood_fill(map_copy, info.player_x, info.player_y, &info);
	free_map(map_copy);
	return (info.found_chest == info.chest && info.exit_reachable);
}
