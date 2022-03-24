/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:29:22 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/22 16:34:23 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_walls(t_data *data)
{
	int	img_width;
	int	img_height;

	data->wall.img = mlx_xpm_file_to_image(data->mlx, "./src/img/wall_01.xpm", \
													&img_width, &img_height);
}

void	load_collectables(t_data *data)
{
	int	img_width;
	int	img_height;

	data->collectable.collectable_1 = mlx_xpm_file_to_image(data->mlx, \
					"./src/img/collectable_01", &img_width, &img_height);
}

void	load_player(t_data *data)
{
	int	img_width;
	int	img_height;

	data->player.img.img = mlx_xpm_file_to_image(data->mlx, \
	"./src/img/img_01.xpm", &img_width, &img_height);
}

void	load_data(t_data *data)
{
	int	img_width;
	int	img_height;

	data->exit.img = mlx_xpm_file_to_image(data->mlx, "./src/img/exit.xpm", \
													&img_width, &img_height);
	data->background.img = mlx_xpm_file_to_image(data->mlx, \
				"./src/img/background.xpm", &img_width, &img_height);
	load_player(data);
	load_collectables(data);
	load_walls(data);
}
