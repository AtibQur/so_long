#include "so_long.h"

void	put_background_on_screen(t_data *data, int col, int row)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < TILESIZE)
	{
		x = 0;
		while (x < TILESIZE)
		{
			color = get_pixel_from_xpm(data->background, x, y);
			pixel_put(&data->img, x + (col * TILESIZE), y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	put_walls_on_screen(t_data *data, int col, int row)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < TILESIZE)
	{
		x = 0;
		while (x < TILESIZE)
		{
			color = get_pixel_from_xpm(data->wall, x, y);
            if (color != 0xFF000000)
			    pixel_put(&data->img, x + (col * TILESIZE), y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	put_player_on_screen(t_data *data, int col, int row)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < TILESIZE)
	{
		x = 0;
		while (x < TILESIZE)
		{
			color = get_pixel_from_xpm(data->player.img, x, y);
            if (color != 0xFF000000)
			    pixel_put(&data->img, x + (col * TILESIZE), y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	put_exit_on_screen(t_data *data, int col, int row)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < TILESIZE)
	{
		x = 0;
		while (x < TILESIZE)
		{
			color = get_pixel_from_xpm(data->exit, x, y);
            if (color != 0xFF000000)
			    pixel_put(&data->img, x + (col * TILESIZE), y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}

void	put_collectable_on_screen(t_data *data, int col, int row)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < TILESIZE)
	{
		x = 0;
		while (x < TILESIZE)
		{
			color = get_pixel_from_xpm(data->collectable.img, x, y);
            if (color != 0xFF000000)
			    pixel_put(&data->img, x + (col * TILESIZE), y + (row * TILESIZE), color);
			x++;
		}
		y++;
	}
}