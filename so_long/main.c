/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:11:52 by aarie-c2          #+#    #+#             */
/*   Updated: 2025/02/05 14:17:40 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx_data;

	init_data(&mlx_data);
	if (!mlx_data)
		return (1);
	if (argc == 2)
	{
		mlx_data->map = read_map(argv[1]);
		if (!mlx_data->map)
		{
			free_all(mlx_data);
			ft_printf("Error\n");
			ft_printf("Map is not valid!\n");
			return (1);
		}
		if (!initiate_screen(mlx_data))
		{
			free_all(mlx_data);
			return (1);
		}
	}
	free_all(mlx_data);
	return (0);
}
