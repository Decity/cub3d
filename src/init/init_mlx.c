#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_exit(data, "mlx_init failed");
	data->win = mlx_new_window(data->mlx, WINDOW_W, WINDOW_H, "cub3D");
	if (!data->win)
		error_exit(data, "mlx_new_window failed");
}
