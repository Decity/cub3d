/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:52:31 by crabin            #+#    #+#             */
/*   Updated: 2026/06/12 19:12:38 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_ray_step(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map_pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_pos.x + 1.0 - player->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map_pos.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_pos.y + 1.0 - player->pos.y)
			* ray->delta_dist.y;
	}
}

static void	ray_initial(t_player player, t_ray *ray, double camera_x)
{
	ray->dir.x = player.dir.x + player.plane.x * camera_x;
	ray->dir.y = player.dir.y + player.plane.y * camera_x;
	if (ray->dir.x < EPSILON && ray->dir.x > -EPSILON)
		ray->dir.x = EPSILON;
	if (ray->dir.y < EPSILON && ray->dir.y > -EPSILON)
		ray->dir.y = EPSILON;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->map_pos.x = (int)player.pos.x;
	ray->map_pos.y = (int)player.pos.y;
	ray->hit = NO_HIT;
}

static void	calc_wall_dist(t_ray *ray)
{
	if (ray->side == SIDE_EASTWEST)
	{
		ray->perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	}
	else
	{
		ray->perp_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
	}
}

static void	get_hit_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == NO_HIT)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_pos.x += ray->step.x;
			ray->side = SIDE_EASTWEST;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_pos.y += ray->step.y;
			ray->side = SIDE_NORTHSOUTH;
		}
		if (is_wall(ray->map_pos.x, ray->map_pos.y, &data->map))
			ray->hit = HIT;
	}
	calc_wall_dist(ray);
	ray->hit_pos.x = data->player.pos.x + ray->perp_wall_dist * ray->dir.x;
	ray->hit_pos.y = data->player.pos.y + ray->perp_wall_dist * ray->dir.y;
}

void	perform_dda(t_data *data, t_ray *ray, double camera_x)
{
	t_player	player;

	player = data->player;
	ray_initial(player, ray, camera_x);
	calc_ray_step(ray, &player);
	get_hit_dda(data, ray);
}
