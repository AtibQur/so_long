#include "so_long.h"

void	check_dead_player(t_data *data)
{
	if (data->attacker.x == data->player.x && \
	    data->attacker.y == data->player.y)
		exit_game("Player got caught! Try again");
}

void	check_enemy_movement(t_data *data)
{
	static int	i;

	// if player is left_top, moves left top
	if (data->attacker.y > data->player.y)
		if (data->attacker.x > data->player.x)
			if ((i == 1) || (i == 4) || (i == 9))
			{
				data->attacker.y--;
				data->attacker.x--;
			}
	// //if player is right_top, move right_top
	if (data->attacker.y > data->player.y) 
		if (data->attacker.x < data->player.x)
			if ((i == 3) || (i == 6) || (i == 12))
			{
				data->attacker.y--;
				data->attacker.x++;
			}
	i++;
	if (i == 12)
		i = 0;
}

void	check_enemy_movement2(t_data *data)
{
	static int	i;

	// if player is left_under, move left_under
	if (data->attacker.y < data->player.y)
		if (data->attacker.x > data->player.x)
			if ((i == 2) || (i == 7) || (i == 4))
			{
				data->attacker.x--;
				data->attacker.y++;
			}
	// if player is rightt_under, move right_under	
	if (data->attacker.y < data->player.y)
		if (data->attacker.x < data->player.x)
			if ((i == 1) || (i == 3) || (i == 5))
			{
				data->attacker.x++;
				data->attacker.y++;
			}
	i++;
	if (i == 8)
		i = 0;
}

void	check_enemy_movement3(t_data *data)
{
	static int	i;

	// if player is left, move left
	if (data->attacker.y == data->player.y)
		if (data->attacker.x > data->player.x)
			if ((i == 1) || (i == 3) || (i == 5))
			{
				data->attacker.x--;
			}
	// if player is rightt, move right	
	if (data->attacker.y == data->player.y)
		if (data->attacker.x < data->player.x)
			if ((i == 2) || (i == 4) || (i == 6))
			{
				data->attacker.x++;
			}
	i++;
	if (i == 6)
		i = 0;
}

void	check_enemy_movement4(t_data *data)
{
	static int	i;

	// if player is top, move top
	if (data->attacker.x == data->player.x)
		if (data->attacker.y > data->player.y)
			if ((i == 1) || (i == 3) || (i == 5))
			{
				data->attacker.y--;
			}
	// if player is bottom, move bottom
	if (data->attacker.x == data->player.x)
		if (data->attacker.y < data->player.y)
			if ((i == 2) || (i == 4) || (i == 6))
			{
				data->attacker.y++;
			}
	i++;
	if (i == 6)
		i = 0;
}