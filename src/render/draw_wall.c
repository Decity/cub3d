/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:26:55 by crabin            #+#    #+#             */
/*   Updated: 2026/06/11 16:57:00 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static int get_wall_colour(t_heading heading)
{
	if (heading == NORTH)
		return (0x009900);
	if (heading == EAST)
		return (0x006600);
	if (heading == SOUTH)
		return (0x4C9900);
	if (heading == WEST)
		return (0x999900);
	else
		return (-1);
}

static t_heading get_wall_side(t_ray *ray, t_player *player)
{
	if (ray->side == SIDE_EASTWEST)
	{
		if (player->pos.x < ray->hit_pos.x)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (player->pos.y < ray->hit_pos.y)
			return (NORTH);
		else
			return (SOUTH);
	}
}

static double get_relative_hit(t_ray *ray)
{
	if (ray->face == NORTH)
		return(1 - (fmod(ray->hit_pos.x, 1)));
	if (ray->face == SOUTH)
		return(fmod(ray->hit_pos.x, 1));
	if (ray->face == EAST)
		return(fmod(ray->hit_pos.y, 1));
	if (ray->face == WEST)
		return(1 - (fmod(ray->hit_pos.y, 1)));
	else
		return (0);
}

void draw_floor_ceiling(t_data *data)
{
	t_ivec2 origin;
	t_ivec2 size;

	origin.x = 0;
	origin.y = 0;

	size.x = WINDOW_W;
	size.y = WINDOW_H / 2;

	draw_box(&data->mlx, origin, size, data->map.ceiling_color);
	origin.y += WINDOW_H / 2;
	draw_box(&data->mlx, origin, size, data->map.floor_color);
}

void put_texture(t_data *data, t_ray *ray, t_ivec2	p, int len)
{
	t_column	col;

	col.start = p;
	col.len = len;
	col.hit_pos = ray->relative_hit;

	put_col_texture(data, &data->map.default_texture[ray->face], &col);
}

void draw_wall(t_data *data, int x, t_ray *ray)
{
	int		line_height;
	int		start;
	int		end;
	t_ivec2	p;

	if (ray->perp_wall_dist < EPSILON)
		ray->perp_wall_dist = EPSILON;
	line_height = (int)(WINDOW_H / ray->perp_wall_dist);
	start = - line_height / 2 + WINDOW_H / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + WINDOW_H / 2;
	if (end >= WINDOW_H)
		end = WINDOW_H - 1;
	p.x = x;
	p.y = start;
	ray->face = get_wall_side(ray, &data->player);
	ray->relative_hit = get_relative_hit(ray);
	put_texture(data, ray, p, end - start);
}
