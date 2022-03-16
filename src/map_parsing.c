/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:40:18 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/16 15:55:55 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*insert_tail(t_map **head, char *content, int x)
{
	t_map	*current_node;
	t_map	*new_node;

	current_node = *head;
	new_node = (t_map *) malloc(sizeof(t_map));
	if (!new_node)
		return (NULL);
	new_node->x = x;
	new_node->content = *content;
	new_node->next = NULL;
	while (current_node != NULL && current_node->next != NULL)
		current_node = current_node->next;
	if (current_node != NULL)
		current_node->next = new_node;
	else
		head = &new_node;
	return (*head);
}

void	parse_position(t_map **map, char *line)
{
	t_map	*point;
	int		x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		point = insert_tail(map, &line[x], x);
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
	line = get_next_line(fd);
	if (!line)
		exit_game("No new line, choose a correct map!");
	while (line)
	{
		parse_position(&data->map, line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
