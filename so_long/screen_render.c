/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:05:09 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 13:58:02 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_imgs(t_mlx *mlx_data)
{
	free_imgs(mlx_data);
	mlx_data->wall_img = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./img/wall.xpm", &mlx_data->img_width, &mlx_data->img_height);
	if (!mlx_data->wall_img)
	{
		free_all(mlx_data);
		exit(1);
	}
	mlx_data->floor_img = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./img/grass.xpm", &mlx_data->img_width, &mlx_data->img_height);
	if (!mlx_data->floor_img)
	{
		free_all(mlx_data);
		exit(1);
	}
	mlx_data->grass_img = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./img/grass.xpm", &mlx_data->img_width, &mlx_data->img_height);
	if (!mlx_data->grass_img)
	{
		free_all(mlx_data);
		exit(1);
	}
}

static void	print_grass(t_mlx *mlx_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx_data->map_height)
	{
		j = 0;
		while (j < mlx_data->map_width)
		{
			mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, \
			mlx_data->grass_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	map_size(t_mlx *mlx_data)
{
	int	i;

	if (!mlx_data->map || !mlx_data->map[0])
		exit(1);
	i = 0;
	mlx_data->map_width = ft_linelen(mlx_data->map[0]);
	while (mlx_data->map[i])
		i++;
	mlx_data->map_height = i;
}

void	print_background(t_mlx *mlx_data)
{
	int	i;
	int	j;

	i = 0;
	print_grass(mlx_data);
	while (i < mlx_data->map_height)
	{
		j = 0;
		while (j < mlx_data->map_width)
		{
			if (mlx_data->map[i][j] == '1')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, \
				mlx_data->wall_img, j * TILE_SIZE, i * TILE_SIZE);
			else if (mlx_data->map[i][j] == '0')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, \
				mlx_data->floor_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
