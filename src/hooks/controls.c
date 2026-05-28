#include "cub3d.h"

/**
 * @brief move_player that works on continuous math (instead of discrete)
 * 
 * @param data 
 */
static void	move_player_c(t_player *player, t_map *map, double dx, double dy)
{
	double		nx;
	double		ny;

	nx = player->pos.x + dx;
	ny = player->pos.y + dy;
	if (nx < 0 || nx >= map.width || ny < 0 || ny >= map.height)
		return ;
	player->pos.x = nx;
	player->pos.y = ny;
} // TODO check how to handle movements towards/past edge -> move to edge??

/**
 * @brief rotate player function that takes LEFT/RIGHT side as argument and
 *	rotates according to defined ROT_speed
 * 
 * @param player 
 * @param side 
 */
static void	rotate_player_c(t_player *player, int side)
{
	double	rotation;
	double	old_dir_x;
	double	old_plane_x;
	t_vec2	*dir;
	t_vec2	*plane;

	if (side == LEFT)
		rotation = ROT_SPEED;
	else
		rotation = -ROT_SPEED;
	dir = &player->dir;
	old_dir_x = dir->x;
	dir->x = dir->x * cos(rotation) - dir->y * sin(rotation);
	dir->y = old_dir_x * sin(rotation) - dir->y * cos(rotation);
	plane = &player->plane;
	old_plane_x = plane.x;
	plane->x = plane->x * cos(rotation) - plane->y * sin(rotation);
	plane->y = old_plane_x * sin(rotation) - plane->y * cos(rotation);
} //TODO think about making a seperate matrix rotation helper

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
