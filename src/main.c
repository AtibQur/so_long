/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:51:51 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/14 17:37:27 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hooks(int keycode, t_vars *vars)
{
	if (keycode == EXIT)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_printf("Bye");
	}
	return (0);
}

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
	t_vars	vars;

	data.mlx = mlx_init();
	img.img = mlx_new_image(data.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "So_long");
	my_mlx_pixel_put(&img, 500, 500, 0xf5f5f5);
	mlx_hook(vars.win, 2, 1L << 0, key_hooks, &vars);
	mlx_put_image_to_window(&data.mlx, data.mlx_win, img.img, 0 ,0);
	mlx_loop(data.mlx);
}
