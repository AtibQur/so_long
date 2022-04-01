/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:06:34 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/01 10:05:11 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_player_addres(t_data *data)
{
	data->player.img.addr = mlx_get_data_addr(data->player.img.img, \
	&data->player.img.bits_per_pixel, &data->player.img.line_length, \
	&data->player.img.endian);
	data->player.img_02.addr = mlx_get_data_addr(data->player.img_02.img, \
	&data->player.img_02.bits_per_pixel, &data->player.img_02.line_length, \
	&data->player.img_02.endian);
	data->player.img_03.addr = mlx_get_data_addr(data->player.img_03.img, \
	&data->player.img_03.bits_per_pixel, &data->player.img_03.line_length, \
	&data->player.img_03.endian);
	data->player.img_04.addr = mlx_get_data_addr(data->player.img_04.img, \
	&data->player.img_04.bits_per_pixel, &data->player.img_04.line_length, \
	&data->player.img_04.endian);
	data->player.current_img = data->player.img;
}

void	initialize_collectable_addres(t_data *data)
{
	data->collectable.img.addr = mlx_get_data_addr(data->collectable.img.img, \
	&data->collectable.img.bits_per_pixel, &data->collectable.img.line_length, \
	&data->collectable.img.endian);
	data->collectable.img_02.addr = mlx_get_data_addr(\
	data->collectable.img_02.img, &data->collectable.img_02.bits_per_pixel, \
	&data->collectable.img_02.line_length, &data->collectable.img_02.endian);
	data->collectable.img_03.addr = mlx_get_data_addr(\
	data->collectable.img_03.img, &data->collectable.img_03.bits_per_pixel, \
	&data->collectable.img_03.line_length, &data->collectable.img_03.endian);
	data->collectable.current_img = data->collectable.img;
}

void	initialize_exit_addres(t_data *data)
{
	data->exit.img.addr = mlx_get_data_addr(data->exit.img.img, \
	&data->exit.img.bits_per_pixel, &data->exit.img.line_length, \
	&data->exit.img.endian);
	data->exit.img_02.addr = mlx_get_data_addr(data->exit.img_02.img, \
	&data->exit.img_02.bits_per_pixel, &data->exit.img_02.line_length, \
	&data->exit.img_02.endian);
	data->exit.img_03.addr = mlx_get_data_addr(data->exit.img_03.img, \
	&data->exit.img_03.bits_per_pixel, &data->exit.img_03.line_length, \
	&data->exit.img_03.endian);
	data->exit.img_04.addr = mlx_get_data_addr(data->exit.img_04.img, \
	&data->exit.img_04.bits_per_pixel, &data->exit.img_04.line_length, \
	&data->exit.img_04.endian);
	data->exit.current_img = data->exit.img;
}

void	initialize_wall_addres(t_data *data)
{
	data->wall.img.addr = mlx_get_data_addr(data->wall.img.img, \
	&data->wall.img.bits_per_pixel, &data->wall.img.line_length, \
	&data->wall.img.endian);
	data->wall.img_02.addr = mlx_get_data_addr(data->wall.img_02.img, \
	&data->wall.img_02.bits_per_pixel, &data->wall.img_02.line_length, \
	&data->wall.img_02.endian);
	data->wall.img_03.addr = mlx_get_data_addr(data->wall.img_03.img, \
	&data->wall.img_03.bits_per_pixel, &data->wall.img_03.line_length, \
	&data->wall.img_03.endian);
	data->wall.current_img = data->wall.img;
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
	r_initialize_attacker_addres(data);
	u_initialize_attacker_addres(data);
	l_initialize_attacker_addres(data);
	initialize_player_addres(data);
	initialize_wall_addres(data);
}
