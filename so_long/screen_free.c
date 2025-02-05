/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:00:21 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 11:03:34 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_objs(t_mlx *mlx_data)
{
	if (mlx_data->player_img)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->player_img);
		mlx_data->player_img = NULL;
	}
	if (mlx_data->chest)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->chest);
		mlx_data->chest = NULL;
	}
	if (mlx_data->exit_img)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->exit_img);
		mlx_data->exit_img = NULL;
	}
}

void	free_imgs(t_mlx *mlx_data)
{
	if (mlx_data->wall_img)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->wall_img);
		mlx_data->wall_img = NULL;
	}
	if (mlx_data->floor_img)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->floor_img);
		mlx_data->floor_img = NULL;
	}
	if (mlx_data->grass_img)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->grass_img);
		mlx_data->grass_img = NULL;
	}
}

void	free_data(t_mlx *mlx_data)
{
	if (mlx_data)
	{
		if (mlx_data->win)
		{
			mlx_destroy_window(mlx_data->mlx, mlx_data->win);
			mlx_data->win = NULL;
		}
		if (mlx_data->mlx)
		{
			mlx_destroy_display(mlx_data->mlx);
			free(mlx_data->mlx);
			mlx_data->mlx = NULL;
		}
		if (mlx_data->map)
			free_map(mlx_data->map);
		free(mlx_data);
	}
}

void	free_all(t_mlx *mlx_data)
{
	free_objs(mlx_data);
	free_imgs(mlx_data);
	free_data(mlx_data);
}

int	close_window(t_mlx *mlx_data)
{
	mlx_loop_end(mlx_data->mlx);
	free_all(mlx_data);
	exit(0);
	return (0);
}
