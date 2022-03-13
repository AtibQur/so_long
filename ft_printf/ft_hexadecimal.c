#include "ft_printf.h"

int	ft_print_hexadecimal(unsigned long n, int up_low)
{
	unsigned long	i;
	unsigned long	total;

	total = 0;
	if (up_low == 'u')
		up_low = 55;
	else if (up_low == 'l')
		up_low = 87;
	if (n / 16)
		total += ft_print_hexadecimal(n / 16, up_low);
	if (n % 16 < 10)
		i = n % 16 + '0';
	else
		i = n % 16 + up_low;
	total += write(1, &i, 1);
	return (total);
}
