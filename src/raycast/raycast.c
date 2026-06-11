/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:50 by crabin            #+#    #+#             */
/*   Updated: 2026/06/11 15:40:23 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void draw_ray(t_data *data, t_ray *ray)
{
	t_ivec2 player;
	t_ivec2 ray_hit;

	player.x = data->player.pos.x * TILE_SIZE + TILE_SIZE / 2;
	player.y = data->player.pos.y * TILE_SIZE + TILE_SIZE / 2;
	ray_hit.x = ray->hit_pos.x * TILE_SIZE;
	ray_hit.y = ray->hit_pos.y * TILE_SIZE;
	draw_line_ivec(data, player, ray_hit, COLOR_TEAL);
}

// calc side_dist
// calc delta_dist
// calc step
// LOOP
	// take step
	// if(in square)
		// set hit bool
		// set map_pos
// track total distance??
void single_ray(t_data *data, t_ray *ray, double camera_x, int column)
{
	perform_dda(data, ray, camera_x);
	draw_wall(data, column, ray);
}

// iterator
// while loop to go over rays from center to one edge -> then other direction
	// cast single ray
	// process result
		// get relevant texture
		// determine floor/ceiling scaling
		// draw result of ray hit to img buffer
	// iterate
void cast_rays(t_data *data)
{
	t_ray	ray;
	double	camera_x;
	int		i;

	i = 0;
	while (i < WINDOW_W)
	{
		camera_x = 2 * i / (double)WINDOW_W - 1;
		single_ray(data, &ray, camera_x, i);
		i++;
	}
}