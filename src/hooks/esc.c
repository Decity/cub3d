#include "cub3d.h"

int	close_window(t_data *data)
{
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.p_mlx, data->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}
