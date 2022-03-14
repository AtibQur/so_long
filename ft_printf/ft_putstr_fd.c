/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:52:53 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/14 10:52:54 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putstr_fd(char *str, int fd)
{
	if (!str)
		return (ft_pf_putstr_fd("(null)", fd));
	if (str)
		return (write(fd, str, ft_pf_strlen(str)));
	return (0);
}
