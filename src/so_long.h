/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:53:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/16 17:16:15 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"

# include <errno.h>
# include <stddef.h>

# define TILESIZE = 32

typedef enum e_keycode {
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53,
}	t_keycode;

typedef enum e_mapcode {
	EMPTY_SPACE = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
	PLAYER_POSITION = 'P'
}	t_mapcode;

typedef struct s_map {
	int				x;
	int				y;
	char			content;
	struct s_map	*next;
}	t_map;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		row;
	int		collumn;
	t_map	*map;
}	t_data;

int		main(int argc, char *argv[]);

/* Initialize the game */
void	initialize_game(t_data *data);

/* Hook events */
int		hook_key(int keycode, t_data *data);
void	hook_events(t_data *data);
int		exit_game(char *error_message);

/* Parse map */
void	parse_map(t_data *data, char *map);
void	parse_position(t_map **map, char *line, int y);
t_map	*insert_tail(t_map **head, char *content, int x, int y);
int		check_rectangle(char *line, int collumn);

#endif