/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:54:39 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/25 15:58:52 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_attacker_existance(t_data *data, int x, int y)
{
			data->attacker.attacker_count++;
			data->attacker.x = x;
			data->attacker.y = y;
}

int	check_content_existance(t_data *data)
{
	t_map	*map;

	map = data->map;
	while (map)
	{
		if (map->content == COLLECTABLE)
			data->collectable.collectable_count++;
		if (map->content == EXIT)
			data->exit_count++;
		if (map->content == PLAYER)
		{
			data->player.player_count++;
			data->player.x = map->x;
			data->player.y = map->y;
		}
		if (map->content == ATTACKER)
			check_attacker_existance(data, map->x, map->y);
		map = map->next;
	}
	if (data->collectable.collectable_count >= 1 && \
		data->exit_count >= 1 && \
		data->player.player_count >= 1)
		return (1);
	return (0);
}

// 1. Check if only "01CPEA" is in the map with strchr
// 2. Check if walls are covered with WALLS (1)
// example -> 111 | the first x/y position is 00/01/02
//         	  101 | check every position that has a x/y position with 0 in it
//            111 | also check if the last x/y position is equal to row number
//                | that means that you're at the end of the wall
//                | column/row starts with 1, x/y starts with 0 
//                | that's why column/row -1.

void	check_map_content(t_map *map, int column, int row)
{
	if (ft_strchr("01CPEA", map->content) == 0)
		exit_game("Invalid characters in map.");
	if (map->x == 0 || map->y == 0 || map->x == column - 1 || map->y == row - 1)
		if (map->content != WALL)
			exit_game("Invalid walls, map is not fully covered with walls!");
}

void	check_map(t_data *data)
{
	t_map	*map;
	int		column;
	int		row;

	map = data->map;
	column = data->collumn;
	row = data->row;
	while (map)
	{
		check_map_content(map, column, row);
		map = map->next;
	}
	if (check_content_existance(data) == 0)
		exit_game("There are not enough players, exits or collectables!");
}
