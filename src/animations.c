/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:45:18 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/30 09:42:08 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->wall.current_img = data->wall.img;
	if (i == 15)
		data->wall.current_img = data->wall.img_02;
	if (i == 30)
		data->wall.current_img = data->wall.img_03;
	if (i == 45)
		data->wall.current_img = data->wall.img_02;
	i++;
	if (i == 60)
		i = 0;
	push_data(data);
	return (0);
}

int	collectable_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->collectable.current_img = data->collectable.img;
	if (i == 10)
		data->collectable.current_img = data->collectable.img_02;
	if (i == 20)
		data->collectable.current_img = data->collectable.img_03;
	i++;
	if (i == 30)
		i = 0;
	push_data(data);
	return (0);
}

int	player_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->player.current_img = data->player.img;
	if (i == 5)
		data->player.current_img = data->player.img_02;
	if (i == 10)
		data->player.current_img = data->player.img_03;
	if (i == 15)
		data->player.current_img = data->player.img_02;
	i++;
	if (i == 20)
		i = 0;
	push_data(data);
	return (0);
}

int	exit_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->exit.current_img = data->exit.img;
	if (i == 5)
		data->exit.current_img = data->exit.img_02;
	if (i == 10)
		data->exit.current_img = data->exit.img_03;
	if (i == 15)
		data->exit.current_img = data->exit.img_02;
	i++;
	if (i == 20)
		i = 0;
	push_data(data);
	return (0);
}

int	animations(t_data *data)
{
	wall_animations(data);
	exit_animations(data);
	player_animations(data);
	attacker_animations(data);
	collectable_animations(data);
	return (0);
}
