#include "cub3d.h"

/**
 * tile - An x/y spot
 * walkable - 0
 * wall - 1
 * player tile = N S E or W
 * leak - a spot that is not covered by walls and thus touches inaccessible 
 * 	space
 */

/**
 * @brief true if the tile can be stood on.
 *
 * NSEW are still in the grid at this point (removed later by
 * set_player_coords), so player tiles count as walkable too.
 */
static bool	is_walkable(char c)
{
	return (c == '0' || is_player_tile(c));
}

/**
 * @brief true if the given tile is out of bounds or a space tile (ie not accessible).
 *
 */
static bool	is_leaking_tile(t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || x >= m->width || y >= m->height)
		return (true);
	if (m->grid[y * m->width + x] == ' ')
		return (true);
	return (false);
}

/**
 * @brief checks the tile's surrounding tiles for leaks.
 *
 * Checks walkable tiles. Does not check non-walkable tiles.
 * Errors if any of the 4 neighbours leaks (space or out of bounds).
 */
static void	check_tile(t_data *data, int x, int y)
{
	t_map	*m;

	m = &data->map;
	if (!is_walkable(m->grid[y * m->width + x]))
		return ;
	if (is_leaking_tile(m, x - 1, y) || is_leaking_tile(m, x + 1, y)
		|| is_leaking_tile(m, x, y - 1) || is_leaking_tile(m, x, y + 1))
		error_exit(data, "map not closed by walls");
}

/**
 * @brief entry point for wall closure validation.
 *
 * Iterates every tile. Every walkable tile must have non-leaking
 * neighbours on all 4 sides. Errors as soon as a leak is found.
 */
void	validate_walls(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			check_tile(data, x, y);
			x++;
		}
		y++;
	}
}
