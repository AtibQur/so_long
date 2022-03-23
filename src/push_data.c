/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:41:32 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/23 17:49:34 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

unsigned int	get_pixel_from_xpm(t_img xpm, int x, int y)
{
    char    *dst;
    dst = xpm.addr + (y * xpm.line_length + x * (xpm.bits_per_pixel / 8));
    return (*(unsigned int*)dst);
}

void	put_image_on_screen(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->background, x, y);
			pixel_put(&data->img, x + (col * TILESIZE), y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	push_data(t_data *data)
{
	t_map	*map;

	map = data->map;
	while (map)
	{
		put_image_on_screen(data, map->x, map->y);
		map = map->next;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
