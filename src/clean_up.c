/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:29:39 by elie              #+#    #+#             */
/*   Updated: 2026/06/09 11:40:15 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Destroys mlx image, window and display. Guards against NULL handles. */
static void	free_mlx(t_data *data)
{
	if (!data->mlx.p_mlx)
		return ;
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.p_mlx, data->mlx.img);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.p_mlx, data->mlx.win);
	mlx_destroy_display(data->mlx.p_mlx);
	free(data->mlx.p_mlx);
	data->mlx.img = NULL;
	data->mlx.win = NULL;
	data->mlx.p_mlx = NULL;
}

/* Frees t_data. NULLs freed values */
int	clean_up(t_data *data)
{
	if (!data)
		return (SUCCESS);
	if (data->fd >= 0)
		close(data->fd);
	free_mlx(data);
	free_cub_content(data->cub_content);
	data->cub_content = NULL;
	// free(data->map.textures.north); // TODO
	// free(data->map.textures.south); // Sorry switched up textures
	// free(data->map.textures.east); // will make a cleanup for that struct
	// free(data->map.textures.west);
	// data->map.textures.north = NULL;
	// data->map.textures.south = NULL;
	// data->map.textures.east = NULL;
	// data->map.textures.west = NULL;
	free(data->map.grid);
	data->map.grid = NULL;
	return (SUCCESS);
}
