/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:28:38 by crabin            #+#    #+#             */
/*   Updated: 2026/06/15 11:55:00 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ============================ System Includes ============================= */

# include <unistd.h>	// read, write, close
# include <fcntl.h>		// open
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit
# include <string.h>	// strerror
# include <errno.h>		// errno
# include <math.h>		// math functions
# include <stdint.h>	// uint8 for colours
# include <sys/time.h>	// gettimeofday

# include <stdbool.h>

# include "defs.h"
# include "controls.h"
# include "mlx.h"
# include "libft.h"

/* =============================== Primitives =============================== */

/** @brief Represents 2D vector in continuous space */
typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

/** @brief Represents 2D vector in discrete space (ie. grid) */
typedef struct s_ivec2
{
	int		x;
	int		y;
}	t_ivec2;

/* ================================= Enums ================================== */

typedef enum e_heading
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_heading;

/* =============================== Subsystems =============================== */

typedef struct s_ray
{
	t_vec2		side_dist;
	t_vec2		delta_dist;
	t_vec2		dir;
	t_vec2		hit_pos;
	t_ivec2		step;
	bool		hit;
	double		relative_hit;
	int			side;
	t_heading	face;
	t_ivec2		map_pos;
	double		perp_wall_dist;
}	t_ray;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
}	t_player;

typedef struct s_column
{
	t_ivec2	start;
	int		len;
	int		true_len;
	double	hit_pos;
}	t_column;

typedef struct s_img
{
	void	*img_pointer;
	char	*addr;
	int		bit_pp;
	int		byt_pp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	char	*path;
	t_img	img;
}	t_texture;

typedef struct s_map
{
	char		*grid;
	int			width;
	int			height;
	int			floor_color;
	int			ceiling_color;
	t_texture	default_texture[4];
}	t_map;

typedef struct s_fps
{
	long	last_ms;
	int		frames;
	int		display_value;
}	t_fps;

typedef struct s_mlx
{
	void	*p_mlx;
	void	*win;
	t_img	screen;
}	t_mlx;

/* ================================== Root ================================== */

typedef struct s_data
{
	t_mlx		mlx;
	char		**cub_content;
	int			fd;
	t_map		map;
	t_player	player;
	t_fps		fps;
}	t_data;

/* ========================== Function Prototypes =========================== */

/* ---------------------------------- init ---------------------------------- */

void	init_data(t_data *data);
void	init_mlx(t_data *data);

/* -------------------------------- helpers --------------------------------- */

char	**cub_split(t_data *data, const char *s);
void	free_cub_content(char **arr);
void	clear_mlx_buff(t_mlx *mlx);
void	set_pixel(t_mlx *mlx, int x, int y, int colour);
bool	in_bounds(int x, int y, t_map *map);
bool	is_wall(int x, int y, t_map *map);

/* --------------------------------- error ---------------------------------- */

void	error_exit(t_data *data, const char *msg);

/* -------------------------------- parsing --------------------------------- */

char	*read_file(t_data *data, const char *path);
void	parse(t_data *data, const char *path);
bool	is_valid_map_char(char c);
bool	is_player_tile(char c);
bool	is_map_line(const char *s);
void	get_map_bounds(t_data *data, char **lines, int *first, int *last);
void	validate_map_block(t_data *data, char **lines, int first, int last);
void	parse_cub_params(t_data *data, char **lines, int map_start);
bool	set_texture(t_data *data, const char *line);
void	validate_texture_paths(t_data *data);
bool	set_color(t_data *data, const char *line);
void	parse_map_data(t_data *data, char **lines, int start, int end);
void	validate_map(t_data *data);
void	validate_walls(t_data *data);
void	set_player_coords(t_data *data);

/* ---------------------------------- run ----------------------------------- */

int		run(t_data *data);
int		clean_up(t_data *data);

/* --------------------------------- hooks ---------------------------------- */

int		on_key(int keycode, t_data *data);
int		close_window(t_data *data);

/* -------------------------------- movement -------------------------------- */

void	rotate_player_c(t_player *player, int side);
void	rotate_matrix(t_vec2 *mat, double rot);
void	move_player_dir(t_player *player, t_map *map, double dx, double dy);

/* -------------------------------- raycast --------------------------------- */

void	cast_rays(t_data *dat);
void	perform_dda(t_data *data, t_ray *ray, double camera_x);
void	draw_wall(t_data *data, int x, t_ray *ray);
void	draw_floor_ceiling(t_data *data);

/* --------------------------------- render --------------------------------- */

int		render(t_data *data);
void	draw_fps(t_data *data);
void	draw_h_line(t_mlx *mlx, t_ivec2 p, int len, int colour);
void	draw_box(t_mlx *mlx, t_ivec2 origin, t_ivec2 size, int colour);

/* -------------------------------- textures -------------------------------- */

void	put_texture(t_data *data, t_ray *ray, t_ivec2 p, t_column *col);

#endif