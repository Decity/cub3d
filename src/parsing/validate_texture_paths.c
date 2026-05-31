#include "cub3d.h"

static void	check_path(t_data *data, const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(data, "texture file not accessible");
	close(fd);
}

void	validate_texture_paths(t_data *data)
{
	check_path(data, data->map.textures.north);
	check_path(data, data->map.textures.south);
	check_path(data, data->map.textures.east);
	check_path(data, data->map.textures.west);
}
