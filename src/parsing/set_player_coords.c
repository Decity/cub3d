#include "cub3d.h"

static void	set_dir(t_vec2 *dir, char c)
{
	if (c == 'N')
	{
		dir->x = 0;
		dir->y = 1;
	}
	else if (c == 'S')
	{
		dir->x = 0;
		dir->y = -1;
	}
	else if (c == 'E')
	{
		dir->x = 1;
		dir->y = 0;
	}
	else
	{
		dir->x = -1;
		dir->y = 0;
	}
}

static void init_camera_plane(t_data *data)
{
	data->player.plane.x = - data->player.dir.y * FOV;
	data->player.plane.y = data->player.dir.x * FOV;

}

static void	set_player_data(t_data *data, int x, int y)
{
	int	idx;

	idx = y * data->map.width + x;
	data->player.pos.x = x;
	data->player.pos.y = y;
	set_dir(&data->player.dir, data->map.grid[idx]);
	init_camera_plane(data);
	data->map.grid[idx] = '0';
}

void	set_player_coords(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (is_player_tile(data->map.grid[y * data->map.width + x]))
				set_player_data(data, x, y);
			x++;
		}
		y++;
	}
}
