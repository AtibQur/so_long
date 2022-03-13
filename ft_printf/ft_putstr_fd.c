#include "ft_printf.h"

int	ft_pf_putstr_fd(char *str, int fd)
{
	if (!str)
		return (ft_pf_putstr_fd("(null)", fd));
	if (str)
		return (write(fd, str, ft_pf_strlen(str)));
	return (0);
}
