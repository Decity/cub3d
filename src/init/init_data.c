#include "cub3d.h"

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->map.floor_color = -1;
	data->map.ceiling_color = -1;
}
