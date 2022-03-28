/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:06:09 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/28 15:36:45 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background_on_screen(t_data *data, int col, int row)
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
			pixel_put(&data->img, x + (col * TILESIZE), \
						y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	put_walls_on_screen(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->wall.current_img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE), \
								y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	put_player_on_screen(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->player.current_img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE), \
							y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	put_exit_on_screen(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->exit, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE), \
				y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	put_collectable_on_screen(t_data *data, int col, int row)
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
			color = get_pixel_from_xpm(data->collectable.current_img, x, y);
			if (color != 0xFF000000)
				pixel_put(&data->img, x + (col * TILESIZE) \
							, y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}