/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attacker_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:40:19 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/29 09:36:15 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_enemy_movement(t_data *data)
{
	if (data->attacker.x == data->player.x && \
		data->attacker.y == data->player.y)
		exit_game("Attacker caught the player! Try again");
}

void	load_attacker(t_data *data)
{
	int	img_width;
	int	img_height;

	data->attacker.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/enemy_01.xpm", &img_width, &img_height);
	data->attacker.img_02.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/enemy_02.xpm", &img_width, &img_height);
	data->attacker.img_03.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/enemy_03.xpm", &img_width, &img_height);
	data->attacker.img_04.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/enemy_04.xpm", &img_width, &img_height);
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
	data->attacker.img_04.addr = mlx_get_data_addr(data->attacker.img_04.img, \
	&data->attacker.img_04.bits_per_pixel, &data->attacker.img_04.line_length, \
	&data->attacker.img_04.endian);
	data->attacker.current_img = data->attacker.img;
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