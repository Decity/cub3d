/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:12:06 by elie              #+#    #+#             */
/*   Updated: 2026/06/09 11:14:44 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Reads the given file and stores the content in data->cub_content. */
static void	load_cub_content(t_data *data, const char *path)
{
	char	*cub_raw;

	cub_raw = read_file(data, path);
	data->cub_content = cub_split(data, cub_raw);
	free(cub_raw);
}

/**
 * @brief Main entry for parsing.
 *
 * Opens the cub file, splits the parameters and the map, and validates
 * the values. Assigns textures, colors, and player spawn data to the
 * given t_data *data struct.
 * 
 * cub_content is kept in data for easier error/clean up handling.
 */
void	parse(t_data *data, const char *path)
{
	int	map_start;
	int	map_end;

	load_cub_content(data, path);
	get_map_bounds(data, data->cub_content, &map_start, &map_end);
	validate_map_block(data, data->cub_content, map_start, map_end);
	parse_cub_params(data, data->cub_content, map_start);
	validate_texture_paths(data);
	parse_map_data(data, data->cub_content, map_start, map_end);
	free_cub_content(data->cub_content);
	data->cub_content = NULL;
	validate_map(data);
	set_player_coords(data);
}
