/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy_movements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:16:00 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/01 15:15:10 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_dead_player(t_data *data)
{
	if (data->attacker.x == data->player.x && \
	data->attacker.y == data->player.y)
	{
		usleep(10000);
		exit_game("Player got caught! Try again");
	}
}

	// 1. if player is left_top, moves left top
	// 2.if player is right_top, move right_top
void	check_enemy_movement(t_data *data)
{
	static int	i;

	if (data->attacker.y > data->player.y && data->attacker.x > data->player.x)
	{
		if ((i == 1) || (i == 4) || (i == 7))
		{
			l_attacker_animations(data);
			data->attacker.y--;
			data->attacker.x--;
		}
	}
	if (data->attacker.y > data->player.y && data->attacker.x < data->player.x)
	{
		if ((i == 2) || (i == 5) || (i == 0))
		{
			r_attacker_animations(data);
			data->attacker.y--;
			data->attacker.x++;
		}
	}
	i++;
	if (i == 8)
		i = 0;
}

	// 1. if player is left_under, move left_under
	// 2. if player is rightt_under, move right_under	
void	check_enemy_movement2(t_data *data)
{
	static int	i;

	if (data->attacker.y < data->player.y && data->attacker.x > data->player.x)
	{
		if ((i == 1) || (i == 4) || (i == 7))
		{
			attacker_animations(data);
			data->attacker.x--;
			data->attacker.y++;
		}	
	}
	if (data->attacker.y < data->player.y && data->attacker.x < data->player.x)
	{
		if ((i == 2) || (i == 5) || (i == 0))
		{
			attacker_animations(data);
			data->attacker.x++;
			data->attacker.y++;
		}
	}
	i++;
	if (i == 8)
		i = 0;
}

	// 1. if player is left, move left
	// 2. if player is rightt, move right	
void	check_enemy_movement3(t_data *data)
{
	static int	i;

	if (data->attacker.y == data->player.y && data->attacker.x > data->player.x)
	{
		if ((i == 1) || (i == 4) || (i == 7))
		{
			l_attacker_animations(data);
			data->attacker.x--;
		}	
	}
	if (data->attacker.y == data->player.y && data->attacker.x < data->player.x)
	{
		if ((i == 2) || (i == 5) || (i == 0))
		{
			r_attacker_animations(data);
			data->attacker.x++;
		}	
	}
	i++;
	if (i == 8)
		i = 0;
}

	// 1. if player is top, move top
	// 2. if player is bottom, move bottom
void	check_enemy_movement4(t_data *data)
{
	static int	i;

	if (data->attacker.x == data->player.x && data->attacker.y > data->player.y)
	{
		if ((i == 1) || (i == 4) || (i == 7))
		{
			u_attacker_animations(data);
			data->attacker.y--;
		}
	}
	if (data->attacker.x == data->player.x && data->attacker.y < data->player.y)
	{
		if ((i == 2) || (i == 5) || (i == 0))
		{
			attacker_animations(data);
			data->attacker.y++;
		}
	}
	i++;
	if (i == 8)
		i = 0;
}
