/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attacker_animations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:56:38 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/01 12:57:16 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	attacker_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->attacker.current_img = data->attacker.img;
	if (i == 1)
		data->attacker.current_img = data->attacker.img_02;
	if (i == 2)
		data->attacker.current_img = data->attacker.img_03;
	i++;
	if (i == 3)
		i = 0;
	push_data(data);
	return (0);
}

int	l_attacker_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->attacker.current_img = data->attacker.l_img;
	if (i == 1)
		data->attacker.current_img = data->attacker.l_img_02;
	if (i == 2)
		data->attacker.current_img = data->attacker.l_img_03;
	i++;
	if (i == 3)
		i = 0;
	push_data(data);
	return (0);
}

int	u_attacker_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->attacker.current_img = data->attacker.u_img;
	if (i == 1)
		data->attacker.current_img = data->attacker.u_img_02;
	if (i == 2)
		data->attacker.current_img = data->attacker.u_img_03;
	i++;
	if (i == 3)
		i = 0;
	push_data(data);
	return (0);
}

int	r_attacker_animations(t_data *data)
{
	static int	i;

	if (i == 0)
		data->attacker.current_img = data->attacker.r_img;
	if (i == 1)
		data->attacker.current_img = data->attacker.r_img_02;
	if (i == 2)
		data->attacker.current_img = data->attacker.r_img_03;
	i++;
	if (i == 3)
		i = 0;
	push_data(data);
	return (0);
}
