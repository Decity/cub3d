#include "cub3d.h"

static const char	*g_map[] = {
	"11111111",
	"10000001",
	"10000001",
	"10000001",
	"10000001",
	"10000001",
	"11111111",
	NULL
};

static void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		perror("mlx_init");
		exit(EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, WINDOW_W, WINDOW_H, "cub3D");
	if (!data->win)
	{
		perror("mlx_new_window");
		exit(EXIT_FAILURE);
	}
}

static void	init_map(t_data *data)
{
	data->map.grid = g_map;
	data->map.width = 0;
	while (g_map[0][data->map.width])
		data->map.width++;
	data->map.height = 0;
	while (g_map[data->map.height])
		data->map.height++;
	data->map.floor_color = 0;
	data->map.ceiling_color = 0;
}

static void	init_player(t_data *data)
{
	data->game.player_x = data->map.width / 2;
	data->game.player_y = data->map.height / 2;
	data->game.angle = 0;
}

void	init(t_data *data)
{
	init_mlx(data);
	init_map(data);
	init_player(data);
}
