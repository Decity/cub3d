/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:52:51 by crabin            #+#    #+#             */
/*   Updated: 2026/06/11 14:46:15 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief move_player that works on continuous math (instead of discrete)
 * 
 * @param data 
 */
void	move_player_c(t_player *player, t_map *map, double dx, double dy)
{
	double		nx;
	double		ny;

	nx = player->pos.x + dx;
	ny = player->pos.y + dy;
	if (nx < 0 || nx >= map->width || ny < 0 || ny >= map->height)
		return ;
	player->pos.x = nx;
	player->pos.y = ny;
} // TODO check how to handle movements towards/past edge -> move to edge??

void perpendicular_vector(t_vec2 vec, t_vec2 *perp)
{
	perp->x = - vec.y;
	perp->y = vec.x;
}

void	move_player_dir(t_player *player, t_map *map, double dx, double dy)
{
	t_vec2	move_vec;
	t_vec2	perp_dir;
	double nx;
	double ny;

	move_vec.x = player->dir.x * dx;
	move_vec.y = player->dir.y * dx;
	perpendicular_vector(player->dir, &perp_dir);
	move_vec.x += perp_dir.x * dy;
	move_vec.y += perp_dir.y * dy;
	nx = player->pos.x + move_vec.x;
	ny = player->pos.y + move_vec.y;
	if (nx < 0 || nx >= map->width || ny < 0 || ny >= map->height)
		return ;
	player->pos.x += move_vec.x;
	player->pos.y += move_vec.y;
}

/**
 * @brief rotates a 2-dimentional matrix by <rot> radians around origin (0,0)
 * 
 * @param mat matrix to be rotated
 * @param rot rotation to be applied in radians
 */
void rotate_matrix(t_vec2 *mat, double rot)
{
	double old_x;
	double old_y;

	old_x = mat->x;
	old_y = mat->y;
	mat->x = mat->x * cos(rot) - mat->y * sin(rot);
	mat->y = old_x * sin(rot) + mat->y * cos(rot);
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
