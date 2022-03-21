/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:06:34 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/21 14:07:48 by hqureshi         ###   ########.fr       */
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
