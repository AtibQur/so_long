/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:29:22 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/29 09:50:21 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_walls(t_data *data)
{
	int	img_width;
	int	img_height;

	data->wall.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/wall_01.xpm", &img_width, &img_height);
	data->wall.img_02.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/wall_02.xpm", &img_width, &img_height);
	data->wall.img_03.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/wall_03.xpm", &img_width, &img_height);
}

void	load_collectables(t_data *data)
{
	int	img_width;
	int	img_height;

	data->collectable.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/collectable_01.xpm", &img_width, &img_height);
	data->collectable.img_02.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/collectable_02.xpm", &img_width, &img_height);
	data->collectable.img_03.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/collectable_03.xpm", &img_width, &img_height);
}

void	load_player(t_data *data)
{
	int	img_width;
	int	img_height;

	data->player.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/img_01.xpm", &img_width, &img_height);
	data->player.img_02.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/img_02.xpm", &img_width, &img_height);
	data->player.img_03.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/img_03.xpm", &img_width, &img_height);
	data->player.img_04.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/img_04.xpm", &img_width, &img_height);
}

void	load_exit(t_data *data)
{
	int	img_width;
	int	img_height;

	data->exit.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/exit_01.xpm", &img_width, &img_height);
	data->exit.img_02.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/exit_02.xpm", &img_width, &img_height);
	data->exit.img_03.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/exit_03.xpm", &img_width, &img_height);
	data->exit.img_04.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/exit_04.xpm", &img_width, &img_height);
}

void	load_data(t_data *data)
{
	int	img_width;
	int	img_height;

	data->background.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/background.xpm", &img_width, &img_height);
	load_player(data);
	load_collectables(data);
	load_attacker(data);
	l_load_attacker(data);
	u_load_attacker(data);
	r_load_attacker(data);
	load_exit(data);
	load_walls(data);
}
