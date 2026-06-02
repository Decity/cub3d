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
			//mlx_pixel_put(data->mlx.p_mlx, data->mlx.win, x + px, y + py, color);
			set_pixel(&data->mlx, x + px, y + py, color);
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
	draw_tile(data, data->player.pos.x * TILE_SIZE,
		data->player.pos.y * TILE_SIZE, COLOR_PLAYER);
}

static void	draw_dir(t_data *data)
{
	int			line_start[2];
	int			line_end[2];
	t_player	player;

	player = data->player;
	line_start[0] = player.pos.x * TILE_SIZE + TILE_SIZE / 2;
	line_start[1] = player.pos.y * TILE_SIZE + TILE_SIZE / 2;
	line_end[0] = (player.pos.x + player.dir.x) * TILE_SIZE + TILE_SIZE / 2;
	line_end[1] = (player.pos.y + player.dir.y) * TILE_SIZE + TILE_SIZE / 2;

	draw_line(data, line_start, line_end, COLOR_WHITE);
}

int	render(t_data *data)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	//mlx_clear_window(mlx->p_mlx, mlx->win); // Check: redundant?
	clear_mlx_buff(mlx);
	draw_map(data);
	draw_player(data);
	draw_dir(data);
	cast_rays(data);
	mlx_put_image_to_window(mlx->p_mlx, mlx->win, mlx->img, 0, 0);
	return (SUCCESS);
}
