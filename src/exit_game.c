#include "so_long.h"

int	exit_game(char *error_message)
{

	if (ft_strnstr(error_message, "GG WP", ft_strlen(error_message)))
	{
		ft_printf("\033[0;32m");
		ft_printf("%s\n\033[0m", error_message);
		exit(EXIT_SUCCESS);
	}
	if (error_message)
	{
		ft_printf("\033[0;31m");
		ft_printf("%s\n\033[0m", error_message);
		exit(EXIT_FAILURE);
	}
	else 
	{
		ft_printf("\033[0;32m");
		ft_printf("Good Game!\n\033[0m");
		exit(EXIT_SUCCESS);

	}
}