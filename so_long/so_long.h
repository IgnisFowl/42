/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:12:21 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 14:13:34 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "libft/include/ft_printf.h"
# include "libft/include/get_next_line.h"
# include "libft/include/libft.h"

# define WIDTH 600
# define HEIGHT 400
# define TILE_SIZE 30

typedef struct s_map {
	int	player;
	int	exits;
	int	chest;
	int	player_x;
	int	player_y;
	int	found_chest;
	int	exit_reachable;
}	t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	void	*wall_img;
	void	*floor_img;
	void	*grass_img;
	void	*chest;
	void	*player_img;
	void	*exit_img;
	int		player_x;
	int		player_y;
	int		img_width;
	int		img_height;
	int		chests_left;
	int		steps;
}	t_mlx;

void	error(char *str);
void	free_map(char **map);
char	**read_map(char *filename);
int		ft_linelen(char *str);
int		validate_elements(char **map);
void	init_map_ints(t_map *map_elem);
void	init_map(t_map *map_elem, char **map);
int		is_rectangular(char **map);
int		is_enclosed(char **map);
int		is_map_valid(char **map);
void	init_data(t_mlx **mlx_data);
int		initiate_screen(t_mlx *mlx_data);
void	map_size(t_mlx *mlx_data);
void	find_player(t_mlx *mlx_data);
void	how_many_chests(t_mlx *mlx_data);
void	print_background(t_mlx *mlx_data);
int		close_window(t_mlx *mlx_data);
int		key_handler(int keycode, t_mlx *mlx_data);
void	render_imgs(t_mlx *mlx_data);
void	render_objs(t_mlx *mlx_data);
void	render_game(t_mlx *mlx_data);
void	print_static_objects(t_mlx *mlx_data);
void	free_all(t_mlx *mlx_data);
void	free_objs(t_mlx *mlx_data);
void	free_imgs(t_mlx *mlx_data);

#endif