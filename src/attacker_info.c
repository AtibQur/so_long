/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attacker_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:40:19 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/30 13:34:27 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_dead_player(t_data *data)
{
	if (data->attacker.x == data->player.x && \
	data->attacker.y == data->player.y)
		exit_game("Player got caught! Try again");
}

void	check_enemy_movement(t_data *data)
{
	static int	i;

	// if player is left_top, moves left top
	if (data->attacker.y > data->player.y)
		if (data->attacker.x > data->player.x)
			if ((i == 1) || (i == 5) || (i == 3))
			{
				data->attacker.y--;
				data->attacker.x--;
			}
	// //if player is right_top, move right_top
	if (data->attacker.y > data->player.y) 
		if (data->attacker.x < data->player.x)
			if ((i == 2) || (i == 4) || (i == 6))
			{
				data->attacker.y--;
				data->attacker.x++;
			}
	i++;
	if (i == 6)
		i = 0;
}

void	check_enemy_movement2(t_data *data)
{
	static int	i;

	// if player is right_under, move right_under
	if (data->attacker.y < data->player.y)
		if (data->attacker.x > data->player.x)
			if ((i == 1) || (i == 3) || (i == 5))
			{
				data->attacker.x--;
				data->attacker.y++;
			}
	// if player is left_under, move left_under	
	if (data->attacker.y < data->player.y)
		if (data->attacker.x < data->player.x)
			if ((i == 2) || (i == 4) || (i == 6))
			{
				data->attacker.x++;
				data->attacker.y++;
			}
	i++;
	if (i == 6)
		i = 0;
}



void	load_attacker(t_data *data)
{
	int	img_width;
	int	img_height;

	data->attacker.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/attacker_01.xpm", &img_width, &img_height);
	data->attacker.img_02.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/attacker_02.xpm", &img_width, &img_height);
	data->attacker.img_03.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/attacker_03.xpm", &img_width, &img_height);
}

void	u_load_attacker(t_data *data)
{
	int	img_width;
	int	img_height;

	data->attacker.u_img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/upsidedown_attacker_01.xpm", &img_width, &img_height);
	data->attacker.u_img_02.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/upsidedown_attacker_02.xpm", &img_width, &img_height);
	data->attacker.u_img_03.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/upsidedown_attacker_03.xpm", &img_width, &img_height);
}

void	r_load_attacker(t_data *data)
{
	int	img_width;
	int	img_height;

	data->attacker.r_img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/rightside_attacker_01.xpm", &img_width, &img_height);
	data->attacker.r_img_02.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/rightside_attacker_02.xpm", &img_width, &img_height);
	data->attacker.r_img_03.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/rightside_attacker_03.xpm", &img_width, &img_height);
}

void	l_load_attacker(t_data *data)
{
	int	img_width;
	int	img_height;

	data->attacker.l_img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/leftside_attacker_01.xpm", &img_width, &img_height);
	data->attacker.l_img_02.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/leftside_attacker_02.xpm", &img_width, &img_height);
	data->attacker.l_img_03.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/leftside_attacker_03.xpm", &img_width, &img_height);
}

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
	data->attacker.u_img_02.addr = mlx_get_data_addr(data->attacker.u_img_02.img, \
	&data->attacker.u_img_02.bits_per_pixel, &data->attacker.u_img_02.line_length, \
	&data->attacker.u_img_02.endian);
	data->attacker.u_img_03.addr = mlx_get_data_addr(data->attacker.u_img_03.img, \
	&data->attacker.u_img_03.bits_per_pixel, &data->attacker.u_img_03.line_length, \
	&data->attacker.u_img_03.endian);
}

void	r_initialize_attacker_addres(t_data *data)
{
	data->attacker.r_img.addr = mlx_get_data_addr(data->attacker.r_img.img, \
	&data->attacker.r_img.bits_per_pixel, &data->attacker.r_img.line_length, \
	&data->attacker.r_img.endian);
	data->attacker.r_img_02.addr = mlx_get_data_addr(data->attacker.r_img_02.img, \
	&data->attacker.r_img_02.bits_per_pixel, &data->attacker.r_img_02.line_length, \
	&data->attacker.r_img_02.endian);
	data->attacker.r_img_03.addr = mlx_get_data_addr(data->attacker.r_img_03.img, \
	&data->attacker.r_img_03.bits_per_pixel, &data->attacker.r_img_03.line_length, \
	&data->attacker.r_img_03.endian);
}

void	l_initialize_attacker_addres(t_data *data)
{
	data->attacker.l_img.addr = mlx_get_data_addr(data->attacker.l_img.img, \
	&data->attacker.l_img.bits_per_pixel, &data->attacker.l_img.line_length, \
	&data->attacker.l_img.endian);
	data->attacker.l_img_02.addr = mlx_get_data_addr(data->attacker.l_img_02.img, \
	&data->attacker.l_img_02.bits_per_pixel, &data->attacker.l_img_02.line_length, \
	&data->attacker.l_img_02.endian);
	data->attacker.l_img_03.addr = mlx_get_data_addr(data->attacker.l_img_03.img, \
	&data->attacker.l_img_03.bits_per_pixel, &data->attacker.l_img_03.line_length, \
	&data->attacker.l_img_03.endian);
}

void	put_attacker_on_screen(t_data *data, int col, int row)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < TILESIZE)
	{
		x = 0;
		while (x < TILESIZE)
		{
			color = get_pixel_from_xpm(data->attacker.current_img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE), \
							y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

int	attacker_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->attacker.current_img = data->attacker.img;
	if (i == 20)
		data->attacker.current_img = data->attacker.img_02;
	if (i == 40)
		data->attacker.current_img = data->attacker.img_03;
	if (i == 60)
		data->attacker.current_img = data->attacker.img_02;
	i++;
	if (i == 80)
		i = 0;
	push_data(data);
	return (0);
}