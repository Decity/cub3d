#include "cub3d.h"

/* Errors if any grid tile is not one of: 0 1 N S E W or space. */
static void	validate_map_tiles(t_data *data)
{
	t_map	*m;
	int		i;
	int		total;

	m = &data->map;
	total = m->width * m->height;
	i = 0;
	while (i < total)
	{
		if (!is_valid_map_char(m->grid[i]))
			error_exit(data, "invalid map character");
		i++;
	}
}

/* Check there is exactly one player tile (N/S/E/W) on the grid.
   Case sensitive. */
static void	validate_player_tile_count(t_data *data)
{
	t_map	*m;
	int		total;
	int		size;
	int		i;

	m = &data->map;
	total = 0;
	size = m->width * m->height;
	i = 0;
	while (i < size)
	{
		if (is_player_tile(m->grid[i]))
			total++;
		i++;
	}
	if (total != 1)
		error_exit(data, "map must contain exactly one player");
}

/**
 * @brief entry point for map grid validation
 *
 * Checks if there's only correct chars in the map (1/0/N/S/E/W/space). This
 * is case sensitive, "n s e w" are incorrect, as per subject.
 * Counts players (should be 1), then checks if the map is surrounded by
 * walls.
 */
void	validate_map(t_data *data)
{
	validate_map_tiles(data);
	validate_player_tile_count(data);
	validate_walls(data);
}
