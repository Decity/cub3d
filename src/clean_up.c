/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:29:39 by elie              #+#    #+#             */
/*   Updated: 2026/06/12 19:04:41 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void clean_struct_img(t_data *data, t_img *img)
{
	if (!img || !img->img_pointer)
		return ;
	mlx_destroy_image(data->mlx.p_mlx, img->img_pointer);
	ft_bzero(img, sizeof(*img));
}

static void clean_struct_texture(t_data *data, t_texture *texture)
{
	free(texture->path);
	texture->path = NULL;
	clean_struct_img(data, &texture->img);
	ft_bzero(texture, sizeof(*texture));
}

static void clean_struct_mlx(t_data *data, t_mlx *mlx)
{
	clean_struct_img(data, &mlx->screen);
	if (mlx->win)
		mlx_destroy_window(data->mlx.p_mlx, data->mlx.win);
	mlx->win = NULL;
	if (mlx->p_mlx)
		mlx_destroy_display(data->mlx.p_mlx);
	free(data->mlx.p_mlx);
	data->mlx.p_mlx = NULL;
	ft_bzero(mlx, sizeof(*mlx));
}

static void clean_struct_map(t_data *data, t_map *map)
{
	free (map->grid);
	map->grid = NULL;
	clean_struct_texture(data, &map->default_texture[NORTH]);
	clean_struct_texture(data, &map->default_texture[SOUTH]);
	clean_struct_texture(data, &map->default_texture[EAST]);
	clean_struct_texture(data, &map->default_texture[WEST]);
	ft_bzero(map, sizeof(*map));
}

/* Frees t_data. NULLs freed values */
int	clean_up(t_data *data)
{
	if (!data)
		return (SUCCESS);
	if (data->fd >= 0)
		close(data->fd);
	free_cub_content(data->cub_content);
	data->cub_content = NULL;
	clean_struct_map(data, &data->map);
	clean_struct_mlx(data, &data->mlx);
	ft_bzero(data, sizeof(*data));
	return (SUCCESS);
}
