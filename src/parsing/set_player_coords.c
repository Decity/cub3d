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
}

static void	set_player_data(t_data *data, int x, int y)
{
	data->game.player_x = x;
	data->game.player_y = y;
	data->game.angle = get_angle(data->map.grid[y * data->map.width + x]);
	data->map.grid[y * data->map.width + x] = '0'; // removes hardcoded player tile
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
