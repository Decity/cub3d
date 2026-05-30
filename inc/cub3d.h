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
# include "../lib/libft/libft.h"

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
	t_ivec2	step;
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
	char		**grid;
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
	t_map		map;
	t_player	player;
}	t_data;

/*
==== Function Prototypes ====
*/

/* init */
/* init_data.c */
void	init_data(t_data *data);

/* init_mlx.c */
void	init_mlx(t_data *data);

/* helpers/cub_split.c */
char	**cub_split(const char *s);
void	free_cub_content(char **arr);

/* error.c */
void	error_exit(const char *msg);

/* validate_args.c */
void	validate_args(int argc);

/* parse */
/* read_file.c */
char	*read_file(const char *path);

/* parse.c */
void	parse(t_data *data, const char *path);

void	get_textures(t_data *data, char **lines);
void	get_colors(t_data *data, char **lines);
void	get_map(t_data *data, char **lines);
void	get_player(t_data *data);

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