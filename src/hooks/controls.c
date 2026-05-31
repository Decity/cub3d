#include "cub3d.h"

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
