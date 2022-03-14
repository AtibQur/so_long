/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:51:51 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/14 16:48:07 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	data;
	t_data	img;
	int i = 450;
	int j = 450;
	data.mlx = mlx_init();
	img.img = mlx_new_image(data.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "So_long");
	while (i <= 950)
	{
		my_mlx_pixel_put(&img, i, j, 0xf5f5f5);
		i++;
		j++;
	}
	mlx_put_image_to_window(&data.mlx, data.mlx_win, img.img, 0 ,0);
	mlx_loop(data.mlx);
}
