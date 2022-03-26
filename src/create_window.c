/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:06:34 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/25 13:59:19 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	initialize_attacker_addres(t_data *data)
{
	data->attacker.img.addr = mlx_get_data_addr(data->attacker.img.img, \
	&data->attacker.img.bits_per_pixel, &data->attacker.img.line_length, \
	&data->attacker.img.endian);
}

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
	data->wall.addr = mlx_get_data_addr(data->wall.img, \
	&data->wall.bits_per_pixel, &data->wall.line_length, &data->wall.endian);
	data->background.addr = mlx_get_data_addr(data->background.img, \
	&data->background.bits_per_pixel, &data->background.line_length, \
	&data->background.endian);
	initialize_exit_addres(data);
	initialize_collectable_addres(data);
	initialize_attacker_addres(data);
	initialize_player_addres(data);
}
