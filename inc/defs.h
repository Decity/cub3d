#ifndef DEFS_H
# define DEFS_H

/* General */
# define SUCCESS 0
# define FAIL 1

/* Window Params */
# define WINDOW_W 1280
# define WINDOW_H 720
# define TILE_SIZE 20
# define LINE_LEN 40

/* Player config */
# define ROT_SPEED 0.1
# define MOV_SPEED 0.3
# define FOV 0.66

/* Colors */
# define COLOR_WALL   0xFFFFFF
# define COLOR_FLOOR  0x333333
# define COLOR_BLACK  0x000000
# define COLOR_PLAYER 0xFFFF00
# define COLOR_WHITE  0xFFFFFF
# define COLOR_TEAL  0x00FFFF

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
