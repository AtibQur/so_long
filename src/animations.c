/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:45:18 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/28 15:52:31 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->wall.current_img = data->wall.img;
	if (i == 20)
		data->wall.current_img = data->wall.img_02;
	if (i == 40)
		data->wall.current_img = data->wall.img_03;
	if (i == 60)
		data->wall.current_img = data->wall.img_02;
	i++;
	if (i == 80)
		i = 0;
	push_data(data);
	return (0);
}

int	collectable_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->collectable.current_img = data->collectable.img;
	if (i == 20)
		data->collectable.current_img = data->collectable.img_02;
	if (i == 40)
		data->collectable.current_img = data->collectable.img_03;
	if (i == 60)
		data->collectable.current_img = data->collectable.img_02;
	i++;
	if (i == 80)
		i = 0;
	push_data(data);
	return (0);
}

int	animations(t_data *data)
{
	wall_animations(data);
	collectable_animations(data);
	return (0);
}
