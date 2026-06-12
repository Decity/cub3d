/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:29:56 by crabin            #+#    #+#             */
/*   Updated: 2026/06/12 19:30:00 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

/* General */
# define SUCCESS 0
# define FAILURE 1

/* Window Params */
# define WINDOW_W 1280
# define WINDOW_H 720
# define TILE_SIZE 20
# define LINE_LEN 40

/* Player config */
# define ROT_SPEED 0.1
# define MOV_SPEED 0.15
# define FOV 0.66

/* Colors */
# define COLOR_WALL   0xFFFFFF
# define COLOR_FLOOR  0x333333
# define COLOR_BLACK  0x000000
# define COLOR_PLAYER 0xFFFF00
# define COLOR_WHITE  0xFFFFFF
# define COLOR_TEAL  0x00FFFF
# define COLOR_RED    0xFF0000
# define COLOR_GREEN  0x00FF00
# define COLOR_BLUE   0x0000FF
# define COLOR_AMBER  0xFFBF00
# define COLOR_GREY_LIGHT  0xCCCCCC
# define COLOR_GREY_MEDIUM 0x808080
# define COLOR_GREY_DARK   0x404040

/* FPS counter */
# define ONE_SECOND_IN_MS 1000

/* Rendering */
//# define BITS_PER_PIXEL 32 // experimenting with dynamic value

/* Map Tiles */
# define EMPTY_SPACE '0'
# define WALL '1'

/* Relative Bearings */
# define LEFT 0
# define RIGHT 1

/* Math */
# define EPSILON 1e-6

/* Raycasting */
# define HIT 1
# define NO_HIT 0
# define SIDE_EASTWEST 0
# define SIDE_NORTHSOUTH 1

#endif
