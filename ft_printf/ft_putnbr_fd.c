/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:52:48 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/14 17:27:23 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putnbr_fd(int n, int fd)
{
	long long int	nbr;
	int				len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len += ft_pf_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		len += ft_pf_putnbr_fd(nbr / 10, fd);
		len += ft_pf_putnbr_fd(nbr % 10, fd);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		len += ft_pf_putchar_fd((nbr + '0'), fd);
	}
	return (len);
}

int	ft_putunbr_fd(int n, int fd)
{
	unsigned int	nbr;
	unsigned int	len;

	nbr = n;
	len = 0;
	if (nbr > 9)
	{
		len += ft_pf_putnbr_fd(nbr / 10, fd);
		len += ft_pf_putnbr_fd(nbr % 10, fd);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		len += ft_pf_putchar_fd((nbr + '0'), fd);
	}
	return (len);
}
