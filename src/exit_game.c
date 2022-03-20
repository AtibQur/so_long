#include "so_long.h"

int	exit_game(char *error_message)
{
	if (error_message)
	{
		ft_printf("%s\n", error_message);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("Game over!");
		exit(EXIT_SUCCESS);
	}
}