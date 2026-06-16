/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:52:51 by crabin            #+#    #+#             */
/*   Updated: 2026/06/16 13:16:26 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_perpendicular_vector(t_vec2 vec, t_vec2 *perp)
{
	perp->x = -vec.y;
	perp->y = vec.x;
}

/* Returns the collision radius with or without sign based on vector v. */
static double	dir_buffer(double v)
{
	if (v < 0)
		return (-COLL_RADIUS);
	return (COLL_RADIUS);
}

/**
 * @brief moves the player, checking each axis separately against the real
 *	float position so sub-cell offsets are kept. A COLL_RADIUS buffer in the
 *	direction of travel stops the camera before it touches the wall, and the
 *	per-axis test lets the player slide along walls instead of sticking.
 */
void	move_player_dir(t_player *player, t_map *map, double dx, double dy)
{
	t_vec2	move_vec;
	t_vec2	perp_dir;
	double	buf_x;
	double	buf_y;

	set_perpendicular_vector(player->dir, &perp_dir);
	move_vec.x = player->dir.x * dx + perp_dir.x * dy;
	move_vec.y = player->dir.y * dx + perp_dir.y * dy;
	buf_x = player->pos.x + move_vec.x + dir_buffer(move_vec.x);
	buf_y = player->pos.y + move_vec.y + dir_buffer(move_vec.y);
	if (!is_wall((int)buf_x, (int)player->pos.y, map))
		player->pos.x += move_vec.x;
	if (!is_wall((int)player->pos.x, (int)buf_y, map))
		player->pos.y += move_vec.y;
}

/**
 * @brief rotates a 2-dimentional matrix by <rot> radians around origin (0,0)
 * 
 * @param mat matrix to be rotated
 * @param rot rotation to be applied in radians
 */
void	rotate_matrix(t_vec2 *mat, double rot)
{
	const double	old_x = mat->x;
	const double	old_y = mat->y;

	mat->x = old_x * cos(rot) - old_y * sin(rot);
	mat->y = old_x * sin(rot) + old_y * cos(rot);
}

/**
 * @brief rotate player function that takes LEFT/RIGHT side as argument and
 *	rotates according to defined ROT_speed
 * 
 * @param player 
 * @param side 
 */
void	rotate_player_c(t_player *player, int side)
{
	double	rotation;

	if (side == LEFT)
		rotation = -ROT_SPEED;
	else
		rotation = ROT_SPEED;
	rotate_matrix(&player->dir, rotation);
	rotate_matrix(&player->plane, rotation);
}
