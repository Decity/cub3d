#include "cub3d.h"

int	run(t_data *data)
{
	render(data);
	mlx_hook(data->win, 2, 1L << 0, (int (*)())(void *)on_key, data);
	mlx_hook(data->win, 17, 0, (int (*)())(void *)close_window, data);
	mlx_hook(data->win, 12, 0, (int (*)())(void *)render, data);
	mlx_loop(data->mlx);
	
	return (EXIT_SUCCESS);
}
