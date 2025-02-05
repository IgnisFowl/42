/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:46:32 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 14:35:54 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_steps(t_mlx *mlx_data)
{
	char	*steps;

	steps = ft_itoa(mlx_data->steps);
	if (!steps)
		return ;
	mlx_string_put(mlx_data->mlx, mlx_data->win, 27, 25, 0xFFFFFF, steps);
	free(steps);
}

static void	re_render_game(t_mlx *mlx_data)
{
	print_background(mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->player_img, \
	mlx_data->player_x * TILE_SIZE, mlx_data->player_y * TILE_SIZE);
	print_static_objects(mlx_data);
	display_steps(mlx_data);
}

static void	update_player_position(t_mlx *mlx_data, int new_x, int new_y)
{
	mlx_data->player_x = new_x;
	mlx_data->player_y = new_y;
	mlx_data->steps++;
	ft_printf("Player walked %d steps.\n", mlx_data->steps);
	re_render_game(mlx_data);
}

static int	check_new_position(t_mlx *mlx_data, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || \
	new_x >= mlx_data->map_width || new_y >= mlx_data->map_height)
	{
		ft_printf("Out of bounds!\n");
		return (0);
	}	
	if (mlx_data->map[new_y][new_x] == '1')
	{
		ft_printf("Hit a wall!\n");
		return (0);
	}	
	if (mlx_data->map[new_y][new_x] == 'C')
	{
		mlx_data->chests_left--;
		ft_printf("Collected a chest! %d chests left.\n", mlx_data->chests_left);
		mlx_data->map[new_y][new_x] = '0';
	}
	if (mlx_data->map[new_y][new_x] == 'E' && mlx_data->chests_left == 0)
	{
		ft_printf("Congratulations!\n");
		close_window(mlx_data);
	}
	update_player_position(mlx_data, new_x, new_y);
	return (1);
}

int	key_handler(int keycode, t_mlx *mlx_data)
{
	int	new_x;
	int	new_y;

	new_x = mlx_data->player_x;
	new_y = mlx_data->player_y;
	if (keycode == 119 || keycode == 65362)
		new_y -= 1;
	else if (keycode == 97 || keycode == 65361)
		new_x -= 1;
	else if (keycode == 115 || keycode == 65364)
		new_y += 1;
	else if (keycode == 100 || keycode == 65363)
		new_x += 1;
	if (keycode == 65307)
		close_window(mlx_data);
	if (keycode == 119 || keycode == 65362 || keycode == 97 || \
	keycode == 65361 || keycode == 115 || keycode == 65364 || \
	keycode == 100 || keycode == 65363)
		check_new_position(mlx_data, new_x, new_y);
	return (0);
}
