/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:41:32 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/25 13:04:49 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	push_data(t_data *data)
{
	t_map	*map;

	map = data->map;
	while (map)
	{
		put_background_on_screen(data, map->x, map->y);
		if (map->content == WALL)
			put_walls_on_screen(data, map->x, map->y);
		if (map->content == EXIT)
			put_exit_on_screen(data, map->x, map->y);
		if (map->content == COLLECTABLE)
			put_collectable_on_screen(data, map->x, map->y);
		if (data->attacker.attacker_count >= 1)
			put_attacker_on_screen(data, data->attacker.x, data->attacker.y);
		put_player_on_screen(data, data->player.x, data->player.y);
		map = map->next;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
