/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:02:13 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/28 14:10:13 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel_from_xpm(t_img xpm, int x, int y)
{
	char	*dst;

	dst = xpm.addr + (y * xpm.line_length + x * (xpm.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
