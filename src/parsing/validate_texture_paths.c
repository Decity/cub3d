/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_paths.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:19:54 by elie              #+#    #+#             */
/*   Updated: 2026/06/09 11:19:54 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_path(t_data *data, const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(data, "texture file not accessible");
	close(fd);
}

void	validate_texture_paths(t_data *data)
{
	check_path(data, data->map.textures.north);
	check_path(data, data->map.textures.south);
	check_path(data, data->map.textures.east);
	check_path(data, data->map.textures.west);
}
