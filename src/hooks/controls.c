#include "cub3d.h"

/**
 * @brief move_player that works on continuous math (instead of discrete)
 * 
 * @param data 
 */
static void	move_player_c(t_player *player, t_map *map)
{
	t_player	player;
	t_map		map;
	double		nx;
	double		ny;

	player = data.player;
	map = data.map;
	nx = player.pos.x + player.dir.x;
	ny = player.pos.y + player.dir.y;
	if (nx < 0 || nx >= map.width || ny < 0 || ny >= map.height)
		return ;
	player.pos.x = nx;
	player.pos.y = ny;
} // TODO check how to handle movements towards/past edge -> move to edge??

static void	move_player(t_data *data, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = data->game.player_x + dx;
	ny = data->game.player_y + dy;
	if (nx < 0 || nx >= data->map.width || ny < 0 || ny >= data->map.height)
		return ;
	data->game.player_x = nx;
	data->game.player_y = ny;
	render(data);
}

static void	rotate_player_c(t_data *data, double d)
{
	data->game.angle += d;
	render(data);
}

static void	rotate_player(t_data *data, double d)
{
	data->game.angle += d;
	render(data);
}

int	on_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W)
		move_player(data, 0, -1);
	else if (keycode == KEY_S)
		move_player(data, 0, 1);
	else if (keycode == KEY_A)
		move_player(data, -1, 0);
	else if (keycode == KEY_D)
		move_player(data, 1, 0);
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		rotate_player(data, -ROT_SPEED);
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		rotate_player(data, ROT_SPEED);
	return (0);
}
