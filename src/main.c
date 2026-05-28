#include "cub3d.h"

void	validate_args(int argc)
{
	if (argc != 2)
		error_exit("usage: ./cub3D <map.cub>");
}

int	main(int argc, char **argv)
{
	t_data	data;

	validate_args(argc);

	init_data(&data);
	parse(&data, argv[1]);
	init_mlx(&data);
	run(&data);
	return (EXIT_SUCCESS);
}
