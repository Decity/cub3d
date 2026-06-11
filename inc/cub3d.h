#ifndef CUB3D_H
# define CUB3D_H

/*
==== System Includes ====
*/

# include <unistd.h>   // read, write, close
# include <fcntl.h>    // open
# include <stdio.h>    // printf, perror
# include <stdlib.h>   // malloc, free, exit
# include <string.h>   // strerror
# include <errno.h>    // errno
# include <math.h>     // math functions
# include <sys/time.h> // gettimeofday

# include <stdbool.h>

# include "defs.h"
# include "controls.h"
# include "mlx.h"
# include "libft.h"

/*
==== Primitives ====
types with no dependencies on other project types
*/

/**
 * @brief Represents 2D vector in continuous space
 */
typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

/**
 * @brief Represents 2D vector in discrete space (ie. grid)
 */
typedef struct s_ivec2
{
	int		x;
	int		y;
}	t_ivec2;

/*
==== Enums ====
*/

typedef	enum e_heading
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_heading;

/*
==== Subsystems ====
*/

typedef struct s_ray
{
	t_vec2	side_dist;
	t_vec2	delta_dist;
	t_vec2	dir;
	t_vec2	hit_pos;
	t_ivec2	step;
	bool	hit;
	int		side;
	t_ivec2	map_pos;
	double	perp_wall_dist;
}	t_ray;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
	
}	t_player;

typedef struct s_textures
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}	t_textures;

typedef struct s_map
{
	char		*grid;
	int			width;
	int			height;
	int			floor_color;
	int			ceiling_color;
	t_textures	textures;
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
	void	*img;
	char	*addr;
	int		bits_p_pixel;
	int		line_len;
	int		endian;
}	t_mlx;

/*
==== Root ====
*/

typedef struct s_data
{
	t_mlx		mlx;
	char		**cub_content;
	int			fd;
	t_map		map;
	t_player	player;
	t_fps		fps;
}	t_data;

/* ==== Function Prototypes ==== */

/* init */
/* init_data.c */
void	init_data(t_data *data);

/* init_mlx.c */
void	init_mlx(t_data *data);

/* helpers/cub_split.c */
char	**cub_split(t_data *data, const char *s);
void	free_cub_content(char **arr);

/* helpers/mlx_helper.c */
void	clear_mlx_buff(t_mlx *mlx);
void	set_pixel(t_mlx *mlx, int x, int y, int colour);

/* helpers/checker.c */
bool in_bounds(int x, int y, t_map *map);
bool is_wall(int x, int y, t_map *map);

/* error.c */
void	error_exit(t_data *data, const char *msg);

/* ============= */
/* == parsing == */
/* ============= */

/* read_file.c */
char	*read_file(t_data *data, const char *path);

/* parse.c */
void	parse(t_data *data, const char *path);

/* parse_chars.c */
bool	is_valid_map_char(char c);
bool	is_player_tile(char c);

/* map_bounds.c */
bool	is_map_line(const char *s);
void	get_map_bounds(t_data *data, char **lines, int *first, int *last);
void	validate_map_block(t_data *data, char **lines, int first, int last);

/* parse_cub_params.c */
void	parse_cub_params(t_data *data, char **lines, int map_start);

/* set_texture.c */
bool	set_texture(t_data *data, const char *line);

/* validate_texture_paths.c */
void	validate_texture_paths(t_data *data);

/* set_color.c */
bool	set_color(t_data *data, const char *line);

/* parse_map_data.c */
void	parse_map_data(t_data *data, char **lines, int start, int end);

/* validate_map.c */
void	validate_map(t_data *data);

/* validate_walls.c */
void	validate_walls(t_data *data);

/* set_player_coords.c */
void	set_player_coords(t_data *data);

/* ============= */

/* run.c */
int		run(t_data *data);

/* hooks/controls.c */
int		on_key(int keycode, t_data *data);

/* hooks/esc.c */
int		close_window(t_data *data);

/* render.c */
int		render(t_data *data);

/* render/fps.c */
void	draw_fps(t_data *data);

/* render/draw_line.c */
void	draw_line(t_data *data, int *line_start, int *line_end, int colour);
void	draw_line_ivec(t_data *data, t_ivec2 start, t_ivec2 end, int colour);
void	draw_v_line(t_mlx *mlx, t_ivec2 p, int len, int colour);
void	draw_h_line(t_mlx *mlx, t_ivec2 p, int len, int colour);
void 	draw_box(t_mlx *mlx, t_ivec2 origin, t_ivec2 size, int colour);

/* clean_up.c */
int		clean_up(t_data *data);

/* movement.c */
void	rotate_player_c(t_player *player, int side);
void	rotate_matrix(t_vec2 *mat, double rot);
void	move_player_dir(t_player *player, t_map *map, double dx, double dy);

/* raycast/raycast.c */
void	cast_rays(t_data *dat);
void	perform_dda(t_data *data, t_ray *ray, double camera_x);
void	draw_wall(t_data *data, int x, t_ray *ray);
void	draw_floor_ceiling(t_data *data);

#endif