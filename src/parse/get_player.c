#include "cub3d.h"

/**
 *	 math rune magic:
 *
 *   N = -PI/2	(-M_PI_2)
 *   S =  PI/2	(M_PI_2)
 *   W =  PI	(M_PI)
 *   E =  0		(0)
 */
static double	get_angle(char c)
{
	if (c == 'N')
		return (-M_PI_2);
	if (c == 'S')
		return (M_PI_2);
	if (c == 'E')
		return (0.0);
	return (M_PI);
} // obsolete

static void set_dir(t_vec2 *dir, char c)
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

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player_data(t_data *data, int x, int y)
{
	data->player.pos.x = x;
	data->player.pos.y = y;
	set_dir(&data->player.dir, data->map.grid[y][x]);
	// player.dir initialisation
	data->map.grid[y][x] = '0'; // removes hardcoded player tile
}

void	get_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (is_player(data->map.grid[y][x]))
				set_player_data(data, x, y);
			x++;
		}
		y++;
	}
}
