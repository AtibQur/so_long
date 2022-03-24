/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:53:47 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/22 11:30:44 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_key(int keycode, t_data *data)
{
	data->moves_count++;
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_win, data->mlx_win);
		exit_game("Exit game...");
		exit(0);
	}
	if (keycode == DOWN)
	{
		ft_printf("Down  | %d\n", data->moves_count);
		data->player.y += 1;
	}
	if (keycode == UP)
	{
			data->player.y -= 1;
	}
	if (keycode == RIGHT)
	{
		ft_printf("Right | %d\n", data->moves_count);
		data->player.x += 1;
	}
	if (keycode == LEFT)
	{
		ft_printf("Left  | %d\n", data->moves_count);
		data->player.x -= 1;
	}
	return (0);
}

void	hook_events(t_data *data)
{
	mlx_key_hook(data->mlx_win, hook_key, data);
	mlx_hook(data->mlx_win, 17, (1L << 17), exit_game, NULL);
}
