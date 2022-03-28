/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:51:51 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/28 11:58:21 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;

	initialize_game(&data, argc);
	parse_map(&data, argv[1]);
	check_map(&data);
	load_data(&data);
	create_window(&data);
	push_data(&data);
	hook_events(&data);
	mlx_loop(data.mlx);
}
