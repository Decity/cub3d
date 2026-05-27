#include "cub3d.h"


// temp barebones check. if it finds a 1, it considers it a map line
static bool	is_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (true);
	return (false);
}

static int	get_map_height(char **cub_content, int start)
{
	int	n;

	n = 0;
	while (cub_content[start + n] && is_map_line(cub_content[start + n]))
		n++;
	return (n);
}

static int	get_map_width(char **cub_content, int start, int height)
{
	int		i;
	int		w;
	size_t	len;

	i = 0;
	w = 0;
	while (i < height)
	{
		len = ft_strlen(cub_content[start + i]);
		if ((int)len > w)
			w = (int)len;
		i++;
	}
	return (w);
}

// returns the map line/row with padding (for consistent sized map rows)
static char	*pad_row(const char *row, int width)
{
	char	*out;
	int		len;
	int		i;

	len = (int)ft_strlen(row);
	out = malloc(width + 1);
	if (!out)
		error_exit("memory allocation failed");
	ft_memcpy(out, row, len);
	i = len;
	while (i < width)
		out[i++] = ' ';
	out[width] = '\0';
	return (out);
}


void	get_map(t_data *data, char **cub_content)
{
	int	start;
	int	i;

	start = 0;
	while (cub_content[start] && !is_map_line(cub_content[start])) // pass non map content
		start++;
	
	data->map.height = get_map_height(cub_content, start);
	data->map.width = get_map_width(cub_content, start, data->map.height);
	data->map.grid = ft_calloc(data->map.height + 1, sizeof(char *));
	if (!data->map.grid)
		error_exit("memory allocation failed");


	i = 0;
	while (i < data->map.height)
	{
		data->map.grid[i] = pad_row(cub_content[start + i], data->map.width);
		i++;
	}
}
