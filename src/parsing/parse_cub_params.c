/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:19:54 by elie              #+#    #+#             */
/*   Updated: 2026/06/11 16:52:11 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Checks if every required paramater has been assigned. */
static void	check_for_missing_params(t_data *data)
{
	if (!data->map.default_texture[NORTH].img.addr)
		error_exit(data, "missing north texture");
	if (!data->map.default_texture[SOUTH].img.addr)
		error_exit(data, "missing south texture");
	if (!data->map.default_texture[WEST].img.addr)
		error_exit(data, "missing west texture");
	if (!data->map.default_texture[EAST].img.addr)
		error_exit(data, "missing east texture");
	if (data->map.floor_color == -1)
		error_exit(data, "missing floor color");
	if (data->map.ceiling_color == -1)
		error_exit(data, "missing ceiling color");
}

/**
 * @brief parses the parameters in the ".cub" file.
 * 
 * Attempts to set color or texture for each parameter in the .cub file.
 * Errors on wrong identifiers, missing element, or duplicate id's
 * Empty lines are simply skipped. Whitespace-only lines causes error.
 * 
 * Map is NOT parsed here. Only the parameters (textures and colors)
 */
void	parse_cub_params(t_data *data, char **lines, int map_start)
{
	int			i;
	t_texture	*default_texture;

	i = 0;
	while (i < 4)
	{
		default_texture = &data->map.default_texture[i];
		ft_bzero((void *)default_texture, sizeof(t_texture));
		i++;
	}
	i = 0;
	while (i < map_start)
	{
		if (lines[i][0] != '\0')
		{
			if (!set_texture(data, lines[i])
				&& !set_color(data, lines[i]))
				error_exit(data, "unknown identifier in scene file");
		}
		i++;
	}
	check_for_missing_params(data);
}
