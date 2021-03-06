/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:53:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/01 17:10:53 by hqureshi         ###   ########.fr       */
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

# define TILESIZE 32

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
	PLAYER = 'P',
	ATTACKER = 'A',
}	t_mapcode;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map {
	int				x;
	int				y;
	char			content;
	struct s_map	*next;
}	t_map;

typedef struct s_collectable {
	int		collectable_count;
	t_img	current_img;
	t_img	img;
	t_img	img_02;
	t_img	img_03;
}	t_collectable;

typedef struct s_player {
	int		player_count;
	int		x;
	int		y;
	t_img	current_img;
	t_img	img;
	t_img	img_02;
	t_img	img_03;
	t_img	img_04;
}	t_player;

typedef struct s_attacker {
	int		attacker_count;
	int		x;
	int		y;
	t_img	current_img;
	t_img	img;
	t_img	img_02;
	t_img	img_03;
	t_img	img_04;
	t_img	r_img;
	t_img	r_img_02;
	t_img	r_img_03;
	t_img	r_img_04;
	t_img	l_img;
	t_img	l_img_02;
	t_img	l_img_03;
	t_img	l_img_04;
	t_img	u_img;
	t_img	u_img_02;
	t_img	u_img_03;
	t_img	u_img_04;
}	t_attacker;

typedef struct s_wall {
	t_img	current_img;
	t_img	img;
	t_img	img_02;
	t_img	img_03;
}	t_wall;

typedef struct s_exit {
	t_img	current_img;
	t_img	img;
	t_img	img_02;
	t_img	img_03;
	t_img	img_04;
}	t_exit;

typedef struct s_data {
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	int				exit_count;
	int				moves_count;
	t_map			*map;
	t_img			background;
	t_exit			exit;
	t_wall			wall;
	t_player		player;
	t_attacker		attacker;
	t_collectable	collectable;
	int				row;
	int				collumn;
}	t_data;

int				main(int argc, char **argv);

/* Initialize the game */
void			initialize_game(t_data *data, int argc);

/* Hook events */
int				hook_key(int keycode, t_data *data);
void			hook_events(t_data *data);
int				exit_game(char *error_message);

/* Parse map */
void			parse_map(t_data *data, char *map);
void			parse_position(t_map **map, char *line, int y);
void			add_new_node(t_map **map, t_map *new_node);
int				check_rectangle(char *line, int collumn);
void			check_ber_extension(char *map);
t_map			*insert_tail(char content, int x, int y);

/* Check map*/
void			check_map(t_data *data);
void			check_map_content(t_map *map, int column, int row);
int				check_content_existance(t_data *data);
void			check_attacker_existance(t_data *data, int x, int y);
void			check_wall_jump(t_data *data);

/* Create window and intialize adresses */
void			create_window(t_data *data);
void			initialize_exit_addres(t_data *data);
void			initialize_attacker_addres(t_data *data);
void			initialize_player_addres(t_data *data);
void			initialize_collectable_addres(t_data *data);
void			initialize_wall_addres(t_data *data);

/* load data/images */
void			load_data(t_data *data);
void			load_player(t_data *data);
void			load_collectables(t_data *data);
void			load_walls(t_data *data);
void			load_exit(t_data *data);
void			load_attacker(t_data *data);

/* pixel functions (get pixels and places on screen) */
void			pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_pixel_from_xpm(t_img xpm, int x, int y);

/* put images */
void			put_background_on_screen(t_data *data, int col, int row);
void			put_walls_on_screen(t_data *data, int col, int row);
void			put_player_on_screen(t_data *data, int col, int row);
void			put_attacker_on_screen(t_data *data, int col, int row);
void			put_exit_on_screen(t_data *data, int col, int row);
void			put_collectable_on_screen(t_data *data, int col, int row);

/* attacker info */
void			put_attacker_on_screen(t_data *data, int col, int row);
void			check_dead_player(t_data *data);
void			check_enemy_movements(t_data *data);
void			check_enemy_movement(t_data *data);
void			check_enemy_movement2(t_data *data);
void			check_enemy_movement3(t_data *data);
void			check_enemy_movement4(t_data *data);
void			load_attacker(t_data *data);
void			u_load_attacker(t_data *data);
void			r_load_attacker(t_data *data);
void			l_load_attacker(t_data *data);
void			initialize_attacker_addres(t_data *data);
void			u_initialize_attacker_addres(t_data *data);
void			r_initialize_attacker_addres(t_data *data);
void			l_initialize_attacker_addres(t_data *data);
int				attacker_animations(t_data *data);
int				l_attacker_animations(t_data *data);
int				r_attacker_animations(t_data *data);
int				u_attacker_animations(t_data *data);

/* animations */
int				animations(t_data *data);
int				wall_animations(t_data *data);
int				exit_animations(t_data *data);
int				collectable_animations(t_data *data);
int				player_animations(t_data *data);

/* push data to screen */
void			push_data(t_data *data);

#endif