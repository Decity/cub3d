#include "cub3d.h"

static int	char_to_color(char c)
{
	if (c == '1')
		return (COLOR_WALL);
	if (c == '0')
		return (COLOR_FLOOR);
	return (COLOR_BLACK);
}

static void	draw_tile(t_data *data, int x, int y, int color)
{
	int	px;
	int	py;

	py = 0;
	while (py < TILE_SIZE)
	{
		px = 0;
		while (px < TILE_SIZE)
		{
			mlx_pixel_put(data->mlx, data->win, x + px, y + py, color);
			px++;
		}
		py++;
	}
}

static void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			draw_tile(data, x * TILE_SIZE, y * TILE_SIZE,
				char_to_color(data->map.grid[y * data->map.width + x]));
			x++;
		}
		y++;
	}
}

static void	draw_player(t_data *data)
{
	draw_tile(data, data->game.player_x * TILE_SIZE,
		data->game.player_y * TILE_SIZE, COLOR_PLAYER);
}

static void	draw_line(t_data *data, int *line_start, int *line_end)
{
	int		steps;
	int		i;
	double	dx;
	double	dy;

	steps = abs(line_end[0] - line_start[0]);
	if (abs(line_end[1] - line_start[1]) > steps)
		steps = abs(line_end[1] - line_start[1]);
	if (steps == 0)
		return ;
	dx = (double)(line_end[0] - line_start[0]) / steps;
	dy = (double)(line_end[1] - line_start[1]) / steps;


	i = 0;
	while (i <= steps)
	{
		mlx_pixel_put(data->mlx, data->win,
			line_start[0] + (int)(dx * i),
			line_start[1] + (int)(dy * i), COLOR_WHITE);
		i++;
	}
}

static void	draw_dir(t_data *data)
{
	int	line_start[2];
	int	line_end[2];

	line_start[0] = data->game.player_x * TILE_SIZE + TILE_SIZE / 2;
	line_start[1] = data->game.player_y * TILE_SIZE + TILE_SIZE / 2;
	line_end[0] = line_start[0] + (int)(cos(data->game.angle) * LINE_LEN);
	line_end[1] = line_start[1] + (int)(sin(data->game.angle) * LINE_LEN);

	draw_line(data, line_start, line_end);
}

int	render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	draw_player(data);
	draw_dir(data);
	
	return (SUCCESS);
}
