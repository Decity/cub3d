/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:29:56 by crabin            #+#    #+#             */
/*   Updated: 2026/06/15 11:55:23 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

/* ================================ General ================================= */

# define SUCCESS			0
# define FAILURE			1

/* ============================= Window Params ============================== */

# define WINDOW_W			1280
# define WINDOW_H			720

/* ============================= Player Config ============================== */

# define ROT_SPEED			0.1
# define MOV_SPEED			0.15
# define FOV				0.66
# define COLL_RADIUS		0.2

/* ================================= Colors ================================= */

# define COLOR_GREEN		0x00FF00

/* ============================== FPS Counter =============================== */

# define ONE_SECOND_IN_MS	1000

/* =============================== Map Tiles ================================ */

# define EMPTY_SPACE		'0'
# define WALL				'1'

/* =========================== Relative Bearings ============================ */

# define LEFT				0
# define RIGHT				1

/* ================================== Math ================================== */

# define EPSILON			1e-6

/* =============================== Raycasting =============================== */

# define HIT				1
# define NO_HIT				0
# define SIDE_EASTWEST		0
# define SIDE_NORTHSOUTH	1

#endif
