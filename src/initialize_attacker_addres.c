/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_attacker_addres.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:37:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/01 12:55:56 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_attacker_addres(t_data *data)
{
	data->attacker.img.addr = mlx_get_data_addr(data->attacker.img.img, \
	&data->attacker.img.bits_per_pixel, &data->attacker.img.line_length, \
	&data->attacker.img.endian);
	data->attacker.img_02.addr = mlx_get_data_addr(data->attacker.img_02.img, \
	&data->attacker.img_02.bits_per_pixel, &data->attacker.img_02.line_length, \
	&data->attacker.img_02.endian);
	data->attacker.img_03.addr = mlx_get_data_addr(data->attacker.img_03.img, \
	&data->attacker.img_03.bits_per_pixel, &data->attacker.img_03.line_length, \
	&data->attacker.img_03.endian);
	data->attacker.current_img = data->attacker.img;
}

void	u_initialize_attacker_addres(t_data *data)
{
	data->attacker.u_img.addr = mlx_get_data_addr(data->attacker.u_img.img, \
	&data->attacker.u_img.bits_per_pixel, &data->attacker.u_img.line_length, \
	&data->attacker.u_img.endian);
	data->attacker.u_img_02.addr = mlx_get_data_addr(\
	data->attacker.u_img_02.img, &data->attacker.u_img_02.bits_per_pixel, \
	&data->attacker.u_img_02.line_length, &data->attacker.u_img_02.endian);
	data->attacker.u_img_03.addr = mlx_get_data_addr(\
	data->attacker.u_img_03.img, &data->attacker.u_img_03.bits_per_pixel, \
	&data->attacker.u_img_03.line_length, &data->attacker.u_img_03.endian);
}

void	r_initialize_attacker_addres(t_data *data)
{
	data->attacker.r_img.addr = mlx_get_data_addr(\
	data->attacker.r_img.img, &data->attacker.r_img.bits_per_pixel, \
	&data->attacker.r_img.line_length, &data->attacker.r_img.endian);
	data->attacker.r_img_02.addr = mlx_get_data_addr(\
	data->attacker.r_img_02.img, &data->attacker.r_img_02.bits_per_pixel, \
	&data->attacker.r_img_02.line_length, &data->attacker.r_img_02.endian);
	data->attacker.r_img_03.addr = mlx_get_data_addr(\
	data->attacker.r_img_03.img, &data->attacker.r_img_03.bits_per_pixel, \
	&data->attacker.r_img_03.line_length, &data->attacker.r_img_03.endian);
}

void	l_initialize_attacker_addres(t_data *data)
{
	data->attacker.l_img.addr = mlx_get_data_addr(\
	data->attacker.l_img.img, &data->attacker.l_img.bits_per_pixel, \
	&data->attacker.l_img.line_length, &data->attacker.l_img.endian);
	data->attacker.l_img_02.addr = mlx_get_data_addr(\
	data->attacker.l_img_02.img, &data->attacker.l_img_02.bits_per_pixel, \
	&data->attacker.l_img_02.line_length, &data->attacker.l_img_02.endian);
	data->attacker.l_img_03.addr = mlx_get_data_addr(\
	data->attacker.l_img_03.img, &data->attacker.l_img_03.bits_per_pixel, \
	&data->attacker.l_img_03.line_length, &data->attacker.l_img_03.endian);
}
