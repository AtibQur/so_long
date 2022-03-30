/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:45:33 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/30 10:14:45 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
