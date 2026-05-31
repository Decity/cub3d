#include "cub3d.h"

static size_t	count_lines(const char *s)
{
	size_t	n;
	size_t	i;

	n = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

void	free_cub_content(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}


// Basically ft split but it keeps empty lines.
char	**cub_split(t_data *data, const char *s)
{
	char	**out;
	size_t	i;
	size_t	start;
	size_t	end;

	out = ft_calloc(count_lines(s) + 1, sizeof(char *));
	if (!out)
		error_exit(data, "memory allocation failed");
	i = 0;
	start = 0;
	end = 0;
	while (1)
	{
		if (s[end] == '\n' || s[end] == '\0')
		{
			out[i] = ft_substr(s, start, end - start);
			if (!out[i++])
			{
				free_cub_content(out);
				error_exit(data, "memory allocation failed");
			}
			if (s[end] == '\0')
				return (out);
			start = end + 1;
		}
		end++;
	}
}
