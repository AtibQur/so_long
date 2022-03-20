/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:51:51 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/16 15:40:46 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	main(int argc, char **argv)
{
	t_data	data;

	initialize_game(&data , argc);
	parse_map(&data, argv[1]);
	check_map(&data);
	data.mlx_win = mlx_new_window(data.mlx, 750, 480, "So_long");
	hook_events(&data);
	mlx_loop(data.mlx);
}
