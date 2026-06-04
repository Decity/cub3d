#include "cub3d.h"

/* True if line contains only map chars (0/1/N/S/E/W/space)
   and has at least one tile char. */
bool	is_map_line(const char *s)
{
	int		i;
	bool	has_tile;

	i = 0;
	has_tile = false;
	while (s[i])
	{
		if (!is_valid_map_char(s[i]))
			return (false);
		if (s[i] != ' ')
			has_tile = true;
		i++;
	}
	return (has_tile);
}

/* Finds index of first and last map line. Errors if no map found. */
void	get_map_bounds(t_data *data, char **lines, int *first, int *last)
{
	int	i;

	*first = -1;
	*last = -1;
	i = 0;
	while (lines[i])
	{
		//printf("line %d, [%zu]: |%s|\n", i, ft_strlen(lines[i]), lines[i]);
		if (is_map_line(lines[i]))
		{
			if (*first == -1)
				*first = i;
			*last = i;
		}
		i++;
	}
	if (*first == -1)
		error_exit(data, "missing map");
}

/* Checks if map is 1 entire block */
void	validate_map_block(t_data *data, char **lines, int first, int last)
{
	int	i;

	i = first;
	while (i <= last)
	{
		if (!is_map_line(lines[i]))
		{
			printf("%s\n", lines[i]);
			error_exit(data, "blank or invalid line inside map");
		}
		i++;
	}
	i = last + 1;
	while (lines[i])
	{
		if (lines[i][0] != '\0')
			error_exit(data, "content after map");
		i++;
	}
}
