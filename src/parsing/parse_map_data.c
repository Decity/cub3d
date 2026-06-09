/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:19:54 by elie              #+#    #+#             */
/*   Updated: 2026/06/09 11:21:03 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* returns thicccest len in the map */
static int	get_width(char **lines, int start, int height)
{
	int		i;
	int		w;
	size_t	len;

	i = 0;
	w = 0;
	while (i < height)
	{
		len = ft_strlen(lines[start + i]);
		if ((int)len > w)
			w = (int)len;
		i++;
	}
	return (w);
}

/* Copies a row into the grid, pads the rest with spaces */
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

/**
 * @brief allocates the grid and copies every map line into it.
 *
 * Each row is copied then padded on the right with spaces so the 
 * grid stays rectangular.
 */
static void	get_map_grid(t_data *data, char **lines, int start)
{
	int	i;

	data->map.grid = malloc(data->map.width * data->map.height + 1);
	if (!data->map.grid)
		error_exit(data, "memory allocation failed");
	i = 0;
	while (i < data->map.height)
	{
		fill_row(data->map.grid + i * data->map.width,
			lines[start + i], data->map.width);
		i++;
	}
	data->map.grid[data->map.width * data->map.height] = '\0';
}

/**
 * @brief entry point for setting up the map height width and grid
 *
 * Use (y * width + x) to access specific "lines"
 *
 * Only copies the chars. Validation of map contents happens later.
 */
void	parse_map_data(t_data *data, char **lines, int start, int end)
{
	data->map.height = end - start + 1;
	data->map.width = get_width(lines, start, data->map.height);
	get_map_grid(data, lines, start);
}
