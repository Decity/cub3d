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

// copies row into grid at row offset, pads remainder with spaces
static void	fill_row(char *dst, const char *row, int width)
{
	int	len;
	int	i;

	len = (int)ft_strlen(row);
	if (len > width)
		len = width;
	ft_memcpy(dst, row, len);
	i = len;
	while (i < width)
		dst[i++] = ' ';
}

void	get_map(t_data *data, char **cub_content)
{
	int	start;
	int	i;

	start = 0;
	while (cub_content[start] && !is_map_line(cub_content[start]))
		start++;

	data->map.height = get_map_height(cub_content, start);
	data->map.width = get_map_width(cub_content, start, data->map.height);
	data->map.grid = malloc(data->map.width * data->map.height + 1);
	if (!data->map.grid)
		error_exit("memory allocation failed");

	i = 0;
	while (i < data->map.height)
	{
		fill_row(data->map.grid + i * data->map.width,
			cub_content[start + i], data->map.width);
		i++;
	}
	data->map.grid[data->map.width * data->map.height] = '\0';
}
