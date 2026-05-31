#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx.p_mlx = mlx_init();
	if (!data->mlx.p_mlx)
		error_exit(data, "mlx_init failed");
	data->mlx.win = mlx_new_window(data->mlx.p_mlx, WINDOW_W, WINDOW_H, "cub3D");
	if (!data->mlx.win)
		error_exit(data, "mlx_new_window failed");
	data->mlx.img = mlx_new_image(data->mlx.p_mlx, WINDOW_W, WINDOW_H);
	if (!data->mlx.img)
		error_exit(data, "mlx_new_image failed");
	data->mlx.addr = mlx_get_data_addr(
			data->mlx.img,
			&data->mlx.bits_p_pixel,
			&data->mlx.line_len,
			&data->mlx.endian
			);
	if (!data->mlx.addr)
		error_exit(data, "mlx_get_data_addr failed");
}
