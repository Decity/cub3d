#include "cub3d.h"

/* Checks argv count and that the scene file has the .cub extension. */
static void	validate_args(t_data *data, int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		error_exit(data, "usage: ./cub3D <map.cub>");
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0)
		error_exit(data, "file must have .cub extension");
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	validate_args(&data, argc, argv); // validate_args after init so exit_error can be called
	parse(&data, argv[1]);
	init_mlx(&data);
	run(&data);
	clean_up(&data);
	return (EXIT_SUCCESS);
}
