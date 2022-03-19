/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:53:47 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/16 16:30:58 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_key(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_win, data->mlx_win);
		exit_game("Exit game...");
		exit(0);
	}
	if (keycode == DOWN)
		ft_printf("Down\n");
	if (keycode == UP)
		ft_printf("Up\n");
	if (keycode == RIGHT)
		ft_printf("Right\n");
	if (keycode == LEFT)
		ft_printf("Left\n");
	return (0);
}

void	hook_events(t_data *data)
{
	mlx_key_hook(data->mlx_win, hook_key, data);
	mlx_hook(data->mlx_win, 17, (1L << 17), exit_game, NULL);
}

int	exit_game(char *error_message)
{
	if (error_message)
	{
		ft_printf("%s\n", error_message);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("Game over!");
		exit(EXIT_SUCCESS);
	}
}
