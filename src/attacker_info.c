/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attacker_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:40:19 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/01 12:57:22 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
