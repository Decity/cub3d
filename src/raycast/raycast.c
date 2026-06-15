/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:50 by crabin            #+#    #+#             */
/*   Updated: 2026/06/12 19:13:21 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// calc side_dist
// calc delta_dist
// calc step
// LOOP
	// take step
	// if(in square)
		// set hit bool
		// set map_pos
// track total distance??
void	single_ray(t_data *data, t_ray *ray, double camera_x, int column)
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
void	cast_rays(t_data *data)
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
