/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:06:34 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/22 17:16:58 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->collumn * TILESIZE, \
								data->row * TILESIZE, "So_long");
	if (!data->mlx)
		exit_game("Creating window failed");
	data->img = mlx_new_image(data->mlx, data->collumn * TILESIZE, \
											data->row * TILESIZE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
								&data->line_length, &data->endian);
}

void	initialize_addres(t_data *data)
{
	data->exit.addr = mlx_get_data_addr(data->exit.img, \
	&data->exit.bits_per_pixel, &data->exit.line_length, &data->exit.endian);
	data->wall.addr = mlx_get_data_addr(data->wall.img, \
	&data->wall.bits_per_pixel, &data->wall.line_length, &data->wall.endian);
	data->background.addr = mlx_get_data_addr(data->background.img, \
	&data->background.bits_per_pixel, &data->background.line_length, \
	&data->background.endian);
	data->player.img.addr = mlx_get_data_addr(data->player.img.img, \
	&data->player.img.bits_per_pixel, &data->player.img.line_length, \
	&data->player.img.endian);
}
