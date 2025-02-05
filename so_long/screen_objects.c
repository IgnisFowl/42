/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:44:30 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 13:58:00 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_mlx *mlx_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlx_data->map_height)
	{
		j = 0;
		while (j < mlx_data->map_width)
		{
			if (mlx_data->map[i][j] == 'P')
			{
				mlx_data->player_x = j;
				mlx_data->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	render_objs(t_mlx *mlx_data)
{
	free_objs(mlx_data);
	mlx_data->player_img = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./img/player.xpm", &mlx_data->img_width, &mlx_data->img_height);
	if (!mlx_data->player_img)
	{
		free_all(mlx_data);
		exit(1);
	}
	mlx_data->exit_img = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./img/door.xpm", &mlx_data->img_width, &mlx_data->img_height);
	if (!mlx_data->exit_img)
	{
		free_all(mlx_data);
		exit(1);
	}
	mlx_data->chest = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./img/chest.xpm", &mlx_data->img_width, &mlx_data->img_height);
	if (!mlx_data->chest)
	{
		free_all(mlx_data);
		exit(1);
	}
}

void	how_many_chests(t_mlx *mlx_data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (i < mlx_data->map_height)
	{
		j = 0;
		while (j < mlx_data->map_width)
		{
			if (mlx_data->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	mlx_data->chests_left = c;
}

void	print_static_objects(t_mlx *mlx_data)
{
	int	i;
	int	j;

	i = 0;
	how_many_chests(mlx_data);
	while (i < mlx_data->map_height)
	{
		j = 0;
		while (j < mlx_data->map_width)
		{
			if (mlx_data->map[i][j] == 'C')
				mlx_put_image_to_window(mlx_data->mlx, \
				mlx_data->win, mlx_data->chest, j * TILE_SIZE, i * TILE_SIZE);
			else if (mlx_data->map[i][j] == 'E' && mlx_data->chests_left == 0)
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, \
				mlx_data->exit_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
