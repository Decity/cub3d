#include "cub3d.h"

static char	**get_cub_content(const char *path)
{
	char	*cub_raw;
	char	**cub_content;

	cub_raw = read_file(path);
	cub_content = cub_split(cub_raw);
	free(cub_raw);
	return (cub_content);
}
/**
 * @brief parses and validates the given .cub file
 * 
 * Currently this is a simple version of parsing. It assumes a correct .cub file.
 * 
 * TODO: validation
 * - validate structure (4 textures, 2 colors, 1 map. any order except map must be at the end. new lines and whitespace allowed, )
 * - validate map (walls, 1 player tile of NESW)
 * - validate textures (are they accessible files?)
 * - validate colors (RGB, max 255 min 0)
 * 
 * @param path Path to the .cub file
 */
void	parse(t_data *data, const char *path)
{
	char	**cub_content;

	cub_content = get_cub_content(path);

	get_textures(data, cub_content);
	get_colors(data, cub_content);
	get_map(data, cub_content);

	free_cub_content(cub_content);

	get_player(data);
}
