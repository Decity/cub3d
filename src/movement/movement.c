/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:52:51 by crabin            #+#    #+#             */
/*   Updated: 2026/06/11 14:49:52 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_perpendicular_vector(t_vec2 vec, t_vec2 *perp)
{
	perp->x = -vec.y;
	perp->y = vec.x;
}

void	move_player_dir(t_player *player, t_map *map, double dx, double dy)
{
	t_vec2		move_vec;
	t_vec2		perp_dir;
	const int	pos_x = (int)player->pos.x;
	const int	pos_y = (int)player->pos.y;

	move_vec.x = player->dir.x * dx;
	move_vec.y = player->dir.y * dx;
	set_perpendicular_vector(player->dir, &perp_dir);
	move_vec.x += perp_dir.x * dy;
	move_vec.y += perp_dir.y * dy;
	if (!is_wall(pos_x + (int)move_vec.x, pos_y, map))
		player->pos.x += move_vec.x;
	if (!is_wall(pos_x, pos_y + (int)move_vec.y, map))
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
