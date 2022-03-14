/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:52:44 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/14 10:52:45 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putpercentage_fd(char c, int fd)
{
	c = '%';
	write(fd, &c, 1);
	return (1);
}
