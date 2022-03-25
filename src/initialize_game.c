/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:54:24 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/25 13:58:13 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initialize the game with mlx_init(); 
// This wll start the whole process and keeps looping with mlx_loop();
// 

void	initialize_game(t_data *data, int argc)
{
	if (argc < 2)
		exit_game("Not enough arguments, try again.");
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_game("Failed to start game");
	data->row = 0;
	data->collumn = 0;
	data->exit_count = 0;
	data->moves_count = 1;
	data->player.player_count = 0;
	data->collectable.collectable_count = 0;
	data->map = NULL;
}
