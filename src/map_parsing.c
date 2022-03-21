/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:40:18 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/21 12:34:56 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_map	*insert_tail(char content, int x, int y)
{
	t_map	*current_node;

	current_node = (t_map *) malloc(sizeof(t_map));
	if (!current_node)
		exit_game("Malloc failed");
	current_node->x = x;
	current_node->y = y;
	current_node->content = content;
	current_node->next = NULL;
	// printf("%c", new_node->content);
	return (current_node);
}

void	add_new_node(t_map **map, t_map *new_node)
{
	t_map	*temp;

	temp = *map;
	if (*map)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	else
		*map = new_node;
}


void	parse_position(t_map **map, char *line, int y)
{
	t_map	*position;
	int		x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		position = insert_tail(line[x], x, y);
		add_new_node(map, position);
		x++;
	}
}

void	parse_map(t_data *data, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_game("Choose a correct map!\n");
	check_ber_extension(map);
	line = get_next_line(fd);
	if (!line)
		exit_game("No new line, choose a correct map!");
	data->collumn = ft_strlen(line) - 1;
	while (line)
	{
		if (check_rectangle(line, data->collumn) == 0)
			exit_game("Invalid Map, choose a correct map!");
		parse_position(&data->map, line, data->row);
		line = get_next_line(fd);
		data->row++;
	}
	free(line);
	close(fd);
}
