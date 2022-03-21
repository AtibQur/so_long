/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:51:51 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/21 18:04:33 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	load_player(t_data *data)
{
	int	img_width;
	int	img_height;

	data->img = mlx_xpm_file_to_image(data->mlx, "./src/images/tanjiro_01.xpm", \
													&img_width, &img_height);
}

void	load_images(t_data *data)
{
	int	img_width;
	int	img_height;
	
	data->img = mlx_xpm_file_to_image(data->mlx, "./src/images/background", \
													&img_width, &img_height);
	load_player(&data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	initialize_game(&data, argc);
	parse_map(&data, argv[1]);
	check_map(&data);
	load_images(&data);
	create_window(&data);
	hook_events(&data);
	mlx_loop(data.mlx);
}
