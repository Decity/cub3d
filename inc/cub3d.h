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

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_step
{
	int		x;
	int		y;
}	t_step;

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
	t_step	step;
	bool	hit;
	int		side;
	t_vec2	map_pos;
}	t_ray;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
	
}	t_player;

// update to take t_player
typedef struct s_game
{
	int			player_x;
	int			player_y;
	double		angle;
}	t_game;

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

/*
==== Root ====
*/

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**cub_content;
	t_map		map;
	t_game		game;
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

/* clean_up.c */
int		clean_up(t_data *data);

#endif