#include "cub3d.h"

static char	*get_texture_path(t_data *data, const char *line)
{
	char	*path;

	while (*line == ' ')
		line++;
	if (!*line)
		error_exit(data, "missing texture path");
	path = ft_strdup(line);
	if (!path)
		error_exit(data, "memory allocation failed");
	return (path);
}

/* Sets a texture path to its slot. Errors on duplicates. */
static void	assign_texture(t_data *data, char **slot, const char *line)
{
	if (*slot != NULL)
		error_exit(data, "duplicate texture identifier");
	*slot = get_texture_path(data, line);
}

/* If line starts with NO/SO/WE/EA + space, stores the texture and returns true.
   Does not error on false */
bool	set_texture(t_data *data, const char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		assign_texture(data, &data->map.textures.north, line + 2);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		assign_texture(data, &data->map.textures.south, line + 2);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		assign_texture(data, &data->map.textures.west, line + 2);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		assign_texture(data, &data->map.textures.east, line + 2);
	else
		return (false);
	return (true);
}
