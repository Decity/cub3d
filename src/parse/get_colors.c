#include "cub3d.h"

static int	parse_byte(const char **s)
{
	int	n;

	n = 0;
	while (ft_isdigit(**s))
	{
		n = n * 10 + (**s - '0');
		(*s)++;
	}
	return (n);
}

static int	parse_color_value(const char *line)
{
	int	r;
	int	g;
	int	b;

	line++;
	while (*line == ' ' || *line == '\t')
		line++;
	r = parse_byte(&line);
	line++;
	g = parse_byte(&line);
	line++;
	b = parse_byte(&line);
	return ((r << 16) | (g << 8) | b);
}

void	get_colors(t_data *data, char **cub_content)
{
	int	i;

	i = 0;
	while (cub_content[i])
	{
		if (cub_content[i][0] == 'F')
			data->map.floor_color = parse_color_value(cub_content[i]);
		else if (cub_content[i][0] == 'C')
			data->map.ceiling_color = parse_color_value(cub_content[i]);
		i++;
	}
}
