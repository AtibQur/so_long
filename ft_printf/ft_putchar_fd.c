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
