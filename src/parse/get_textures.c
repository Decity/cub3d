#include "cub3d.h"


void	get_textures(t_data *data, char **cub_content)
{
	int		i;
	char	*line;

	i = 0;
	while (cub_content[i])
	{
		line = cub_content[i];
		if (line[0] == 'N' && line[1] == 'O')
			data->map.textures.north = ft_strtrim(line + 2, " \t");
		else if (line[0] == 'S' && line[1] == 'O')
			data->map.textures.south = ft_strtrim(line + 2, " \t");
		else if (line[0] == 'W' && line[1] == 'E')
			data->map.textures.west = ft_strtrim(line + 2, " \t");
		else if (line[0] == 'E' && line[1] == 'A')
			data->map.textures.east = ft_strtrim(line + 2, " \t");
		i++;
	}
}
