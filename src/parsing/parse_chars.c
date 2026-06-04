#include "cub3d.h"

/* True if c is one of the chars allowed in a map line:
   the 6 tile chars plus space. */
bool	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

/* True if c is a player spawn tile (N/S/E/W). */
bool	is_player_tile(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
