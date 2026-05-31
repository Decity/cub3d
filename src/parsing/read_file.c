#include "cub3d.h"

static char	*append_line(t_data *data, char *out, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(out, line);
	free(out);
	free(line);
	if (!tmp)
		error_exit(data, "memory allocation failed");
	return (tmp);
}

// reads the given file with gnl. Appends each line into one large char
char	*read_file(t_data *data, const char *path)
{
	int		fd;
	char	*line;
	char	*out;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(data, strerror(errno));
	out = ft_strdup("");
	if (!out)
		error_exit(data, "memory allocation failed");
	line = get_next_line(fd);
	while (line != NULL)
	{
		out = append_line(data, out, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (out);
}
