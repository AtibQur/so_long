/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:06:34 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/28 13:11:39 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_player_addres(t_data *data)
{
	data->player.img.addr = mlx_get_data_addr(data->player.img.img, \
	&data->player.img.bits_per_pixel, &data->player.img.line_length, \
	&data->player.img.endian);
}

void	initialize_collectable_addres(t_data *data)
{
	data->collectable.img.addr = mlx_get_data_addr(data->collectable.img.img, \
	&data->collectable.img.bits_per_pixel, &data->collectable.img.line_length, \
	&data->collectable.img.endian);
}

void	initialize_exit_addres(t_data *data)
{
	data->exit.addr = mlx_get_data_addr(data->exit.img, \
	&data->exit.bits_per_pixel, &data->exit.line_length, &data->exit.endian);
}

void	initialize_wall_addres(t_data *data)
{
	data->wall.img.addr = mlx_get_data_addr(data->wall.img.img, \
	&data->wall.img.bits_per_pixel, &data->wall.img.line_length, \
	&data->wall.img.endian);
	data->wall.img_02.addr = mlx_get_data_addr(data->wall.img.img, \
	&data->wall.img.bits_per_pixel, &data->wall.img.line_length, \
	&data->wall.img.endian);
	data->wall.img_03.addr = mlx_get_data_addr(data->wall.img.img, \
	&data->wall.img.bits_per_pixel, &data->wall.img.line_length, \
	&data->wall.img.endian);
}

void	create_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->collumn * TILESIZE, \
								data->row * TILESIZE, "So_long");
	if (!data->mlx)
		exit_game("Creating window failed");
	data->img.img = mlx_new_image(data->mlx, data->collumn * TILESIZE, \
											data->row * TILESIZE);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel \
								, &data->img.line_length, &data->img.endian);
	data->background.addr = mlx_get_data_addr(data->background.img, \
	&data->background.bits_per_pixel, &data->background.line_length, \
	&data->background.endian);
	initialize_exit_addres(data);
	initialize_collectable_addres(data);
	initialize_attacker_addres(data);
	initialize_player_addres(data);
	initialize_wall_addres(data);
}
