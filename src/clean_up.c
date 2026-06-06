#include "cub3d.h"

/* Frees t_data. NULLs freed values */
int	clean_up(t_data *data)
{
	if (!data)
		return (SUCCESS);
	free_cub_content(data->cub_content);
	data->cub_content = NULL;
	// free(data->map.textures.north); // TODO
	// free(data->map.textures.south); // Sorry switched up textures
	// free(data->map.textures.east); // will make a cleanup for that struct
	// free(data->map.textures.west);
	// data->map.textures.north = NULL;
	// data->map.textures.south = NULL;
	// data->map.textures.east = NULL;
	// data->map.textures.west = NULL;
	free(data->map.grid);
	data->map.grid = NULL;
	return (SUCCESS);
}




