/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:58:10 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/21 12:42:18 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(char *line, int collumn)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (i == collumn)
		return (1);
	else
		return (0);
}

void	check_ber_extension(char *map)
{
	int	length;

	length = ft_strlen(map);
	if (ft_strnstr(map, ".ber", length) == 0)
		exit_game("Wrong extension, use a file with .ber");
}
