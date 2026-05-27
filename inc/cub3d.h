#ifndef CUB3D_H
# define CUB3D_H

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
# include "../lib/libft/include/libft.h"

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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_game		game;
}	t_data;

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
