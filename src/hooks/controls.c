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
	if (nx < 0 || nx >= map->width || ny < 0 || ny >= map->height)
		return ;
	player->pos.x = nx;
	player->pos.y = ny;
} // TODO check how to handle movements towards/past edge -> move to edge??

static void rotate_matrix(t_vec2 *mat, double rot)
{
	double old_x;
	double old_y;

	old_x = mat->x;
	old_y = mat->y;

	mat->x = mat->x * cos(rot) - mat->y * sin(rot);
	mat->y = old_x * sin(rot) + mat->y * cos(rot);
}

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

	if (side == LEFT)
		rotation = ROT_SPEED;
	else
		rotation = -ROT_SPEED;
	rotate_matrix(&player->dir, rotation);
	rotate_matrix(&player->plane, rotation);
} //TODO think about making a seperate matrix rotation helper

// static void	move_player(t_data *data, int dx, int dy)
// {
// 	int	nx;
// 	int	ny;

// 	nx = data->game.player_x + dx;
// 	ny = data->game.player_y + dy;
// 	if (nx < 0 || nx >= data->map.width || ny < 0 || ny >= data->map.height)
// 		return ;
// 	data->game.player_x = nx;
// 	data->game.player_y = ny;
// 	render(data);
// }

// static void	rotate_player(t_data *data, double d)
// {
// 	data->game.angle += d;
// 	render(data);
// }

int	on_key(int keycode, t_data *data)
{
	t_player	*player;
	t_map		*map;

	player = &data->player;
	map = &data->map;
	
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W)
		move_player_c(player, map, 0, -MOV_SPEED);
	else if (keycode == KEY_S)
		move_player_c(player, map, 0, MOV_SPEED);
	else if (keycode == KEY_A)
		move_player_c(player, map, -MOV_SPEED, 0);
	else if (keycode == KEY_D)
		move_player_c(player, map, MOV_SPEED, 0);
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		rotate_player_c(player, LEFT);
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		rotate_player_c(player, RIGHT);
	render(data);
	return (0);
}
