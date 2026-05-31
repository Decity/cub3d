#include "cub3d.h"

/* Basically atoi. errors if not digit immediately (ie negative val)*/
static int	parse_byte(t_data *data, const char **s)
{
	int	n;
	int	has_digit;

	n = 0;
	has_digit = 0;
	while (ft_isdigit(**s))
	{
		n = n * 10 + (**s - '0');
		if (n > 255)
			error_exit(data, "color value out of range");
		has_digit = 1;
		(*s)++;
	}
	if (!has_digit)
		error_exit(data, "invalid color value");
	return (n);
}

/**
 * @brief parses "R,G,B" into a 0xRRGGBB int for floor and ceiling colors.
 *
 * Skips the identifier (F/C) and spaces, reads R, G, B separated by
 * a single comma each. 
 * 
 * Errors on missing commas, missing digits, incorrect values, or any trailing characters .
 */
static int	parse_color_value(t_data *data, const char *line)
{
	int	r;
	int	g;
	int	b;

	line++;
	while (*line == ' ')
		line++;
	r = parse_byte(data, &line);
	if (*line++ != ',')
		error_exit(data, "invalid color format");
	g = parse_byte(data, &line);
	if (*line++ != ',')
		error_exit(data, "invalid color format");
	b = parse_byte(data, &line);
	if (*line) // checks for any char after the final value
		error_exit(data, "invalid color format");
	return ((r << 16) | (g << 8) | b);
}

/**
 * @brief tries to parse line as a floor or ceiling color.
 *
 * Returns true if a color is succesfully assigned
 * 
 * Errors on duplicates or incorrect values
 * 
 * Returns false instead of error so it can attempt on another line
 */
bool	set_color(t_data *data, const char *line)
{
	if (line[0] == 'F' && line[1] == ' ')
	{
		if (data->map.floor_color != -1)
			error_exit(data, "duplicate floor color");
		data->map.floor_color = parse_color_value(data, line);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		if (data->map.ceiling_color != -1)
			error_exit(data, "duplicate ceiling color");
		data->map.ceiling_color = parse_color_value(data, line);
	}
	else
		return (false);
	return (true);
}
