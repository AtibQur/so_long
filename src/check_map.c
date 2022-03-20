#include "so_long.h"


// 1. Check if only "01CPE" is in the map with strchr
// 2. Check if walls are covered with WALLS (1)
// example -> 111 | the first x/y position is 00/01/02
//         	  101 | check every position that has a x/y position with 0 in it
//            111 | also check if the last x/y position is equal to row number
//                | that means that you're at the end of the wall
//                | column/row starts with 1, x/y starts with 0 
//                | that's why column/row -1.

void	check_map_content(t_map *map, int column, int row)
{
	if (ft_strchr("01CPE", map->content) == 0)
		exit_game("Invalid characters in map.");

	if (map->x == 0 || map->y == 0 || map->x == column - 1 || map->y == row - 1 )
	{
		if (map->content != WALL)
			exit_game("Map is not fully covered with walls!");
	}
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
}