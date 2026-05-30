#include "cub3d.h"

int	run(t_data *data)
{
	render(data);
	mlx_hook(data->mlx.win, 2, 1L << 0, (int (*)())(void *)on_key, data);
	mlx_hook(data->mlx.win, 17, 0, (int (*)())(void *)close_window, data);
	mlx_hook(data->mlx.win, 12, 0, (int (*)())(void *)render, data);
	mlx_loop(data->mlx.p_mlx);
	
	return (EXIT_SUCCESS);
}
