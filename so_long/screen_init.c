/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:23:59 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 14:13:38 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_mlx **mlx_data)
{
	*mlx_data = malloc(sizeof(t_mlx));
	if (!*mlx_data)
		return ;
	(*mlx_data)->mlx = NULL;
	(*mlx_data)->win = NULL;
	(*mlx_data)->map = NULL;
	(*mlx_data)->wall_img = NULL;
	(*mlx_data)->floor_img = NULL;
	(*mlx_data)->grass_img = NULL;
	(*mlx_data)->player_img = NULL;
	(*mlx_data)->chest = NULL;
	(*mlx_data)->exit_img = NULL;
	(*mlx_data)->chests_left = 0;
	(*mlx_data)->img_width = 0;
	(*mlx_data)->img_height = 0;
	(*mlx_data)->map_width = 0;
	(*mlx_data)->map_height = 0;
	(*mlx_data)->player_x = 0;
	(*mlx_data)->player_y = 0;
	(*mlx_data)->steps = 0;
}

void	render_game(t_mlx *mlx_data)
{
	render_imgs(mlx_data);
	render_objs(mlx_data);
	map_size(mlx_data);
	print_background(mlx_data);
	find_player(mlx_data);
	how_many_chests(mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->player_img, \
	mlx_data->player_x * TILE_SIZE, mlx_data->player_y * TILE_SIZE \
	);
	print_static_objects(mlx_data);
}

int	initiate_screen(t_mlx *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
	{
		free_all(mlx_data);
		return (0);
	}
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "So long!");
	if (!mlx_data->win)
	{
		free_all(mlx_data);
		return (0);
	}
	render_game(mlx_data);
	mlx_hook(mlx_data->win, 2, 1L << 0, key_handler, mlx_data);
	mlx_hook(mlx_data->win, 17, 0, close_window, mlx_data);
	mlx_loop(mlx_data->mlx);
	return (1);
}
