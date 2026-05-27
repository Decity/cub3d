#ifndef CUB3D_H
# define CUB3D_H

/*
==== System Includes ====
*/

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <math.h>
# include <sys/time.h>
# include "mlx.h"
# include "defs.h"
# include "controls.h"

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

typedef struct s_map
{
	const char	**grid;
	int			width;
	int			height;
	int			floor_color;
	int			ceiling_color;
	// textures
}	t_map;

/*
==== Root ====
*/

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_game		game;
	t_player	player;
}	t_data;

/*
==== Function Prototypes ====
*/

/* init.c */
void	init(t_data *data);

/* parse.c */
int		parse(t_data *data);

/* validate_params.c */
int		validate_params(t_data *data);

/* validate_map.c */
int		validate_map(t_data *data);

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