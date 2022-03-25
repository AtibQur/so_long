/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:53:47 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/25 13:02:18 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_movement(t_data *data, int row, int col, char *move)
{
	t_map	*map;

	map = data->map;
	ft_printf("%s    | %d\n", move, data->moves_count++);
	while (map)
	{
		if (map->x == row && map->y == col && map->content != WALL)
		{
			if (map->content == COLLECTABLE)
			{
				data->collectable.collectable_count--;
				map->content = EMPTY_SPACE;
			}
			if (map->content == EXIT)
				if (data->collectable.collectable_count == 0)
					exit_game("GG WP");
			return (1);
		}
		map = map->next;
	}
	return (0);
}

char	*key(int move)
{
	char	*ret;

	if (move == DOWN)
		ret = "Down ";
	if (move == UP)
		ret = "Up   ";
	if (move == RIGHT)
		ret = "Right";
	if (move == LEFT)
		ret = "Left ";
	return (ret);
}

int	hook_key(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_win, data->mlx_win);
		exit_game("Exit game...");
	}
	if (keycode == DOWN)
		if (check_movement(data, data->player.x, data->player.y + 1, key(DOWN)))
			data->player.y += 1;
	if (keycode == UP)
		if (check_movement(data, data->player.x, data->player.y - 1, key(UP)))
			data->player.y -= 1;
	if (keycode == RIGHT)
		if (check_movement(data, data->player.x +1, data->player.y, key(RIGHT)))
			data->player.x += 1;
	if (keycode == LEFT)
		if (check_movement(data, data->player.x - 1, data->player.y, key(LEFT)))
			data->player.x -= 1;
	push_data(data);
	return (0);
}

void	hook_events(t_data *data)
{
	mlx_key_hook(data->mlx_win, hook_key, data);
	mlx_hook(data->mlx_win, 17, (1L << 17), exit_game, NULL);
}
