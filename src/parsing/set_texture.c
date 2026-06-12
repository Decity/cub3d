/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:19:54 by elie              #+#    #+#             */
/*   Updated: 2026/06/12 19:26:37 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief 
 * Opens .xpm file pointed to by texture->path, loads texture into memory and 
 * initalises struct members, saves pointer to start of pixel buffer into 
 * texture->addr
 * 
 * @param data 
 * @param texture pointer to struct holding texture data
 */
static int	init_texture(t_data	*data, t_texture *texture)
{
	texture->img.img_pointer = mlx_xpm_file_to_image(
			data->mlx.p_mlx,
			texture->path,
			&texture->img.width,
			&texture->img.height
			);
	if (!texture->img.img_pointer)
		return (FAILURE);
	texture->img.addr = mlx_get_data_addr(
			texture->img.img_pointer,
			&texture->img.bit_pp,
			&texture->img.line_len,
			&texture->img.endian
			);
	if (!texture->img.addr)
		return (FAILURE);
	texture->img.byt_pp = texture->img.bit_pp / 8;
	return (SUCCESS);
}

static char	*get_texture_path(t_data *data, const char *line)
{
	char	*path;

	while (*line == ' ')
		line++;
	if (!*line)
		error_exit(data, "missing texture path");
	path = ft_strdup(line);
	if (!path)
		error_exit(data, "memory allocation failed");
	return (path);
}

/* Sets a texture path to its slot. Errors on duplicates. */
static void	assign_texture(t_data *data, t_texture *texture, const char *line)
{
	if (texture->path != NULL)
		error_exit(data, "duplicate texture identifier");
	texture->path = get_texture_path(data, line);
	if (init_texture(data, texture) == FAILURE)
		error_exit(data, "texture init failed");
}

/* If line starts with NO/SO/WE/EA + space, stores the texture and returns true.
   Does not error on false */
bool	set_texture(t_data *data, const char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		assign_texture(data, &data->map.default_texture[NORTH], line + 2);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		assign_texture(data, &data->map.default_texture[SOUTH], line + 2);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		assign_texture(data, &data->map.default_texture[WEST], line + 2);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		assign_texture(data, &data->map.default_texture[EAST], line + 2);
	else
		return (false);
	return (true);
}
