/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:52:33 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/14 17:28:18 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_char(va_list arg_list, const char *format)
{
	int	len;

	len = 0;
	if (*format == 'c')
		return (ft_pf_putchar_fd(va_arg(arg_list, int), 1));
	if (*format == 's')
		return (ft_pf_putstr_fd(va_arg(arg_list, char *), 1));
	if (*format == 'p')
		return (ft_pointer(va_arg(arg_list, unsigned long), 'l'));
	if (*format == 'd' || *format == 'i')
		return (ft_pf_putnbr_fd(va_arg(arg_list, int), 1));
	if (*format == 'u')
		return (ft_putunbr_fd(va_arg(arg_list, unsigned int), 1));
	if (*format == 'x')
		return (ft_print_hexadecimal(va_arg(arg_list, unsigned int), 'l'));
	if (*format == 'X')
		return (ft_print_hexadecimal(va_arg(arg_list, unsigned int), 'u'));
	if (*format == '%')
	{
		return (ft_putpercentage_fd('%', 1));
	}
	return (len);
}

int	ft_printf(const	char *format, ...)
{
	va_list	arg_list;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(arg_list, format);
	while (format[i])
	{
		if (format[i] == '\0')
			return (0);
		if (format[i] == '%')
		{
			total += ft_check_char(arg_list, &format[i + 1]);
			i++;
		}
		else
		{
			ft_pf_putchar_fd(format[i], 1);
			total++;
		}
		i++;
	}
	va_end(arg_list);
	return (total);
}
