#include "cub3d.h"

int	on_key(int keycode, t_data *data)
{
	t_player	*player;
	t_map		*map;
	t_vec2		move;

	player = &data->player;
	map = &data->map;
	
	move.x = 0;
	move.y = 0;
	if (keycode == KEY_ESC)
		close_window(data);
	if (keycode == KEY_W)
	{
		move.x += MOV_SPEED;
	}
	if (keycode == KEY_S)
	{
		move.x += -MOV_SPEED;
	}
	if (keycode == KEY_A)
	{
		move.y += - MOV_SPEED;
	}
	if (keycode == KEY_D)
	{
		move.y += MOV_SPEED;
	}
	move_player_dir(player, map, move.x, move.y);

	if (keycode == KEY_Q || keycode == KEY_LEFT)
		rotate_player_c(player, LEFT);
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		rotate_player_c(player, RIGHT);
	return (0);
}
