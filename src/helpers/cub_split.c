/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:33:29 by elie              #+#    #+#             */
/*   Updated: 2026/06/09 11:36:56 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* Frees the line array and raw source buffer, then exits. */
static void	split_fail(t_data *data, char **out, char *raw)
{
	free_cub_content(out);
	free(raw);
	error_exit(data, "memory allocation failed");
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
		split_fail(data, NULL, (char *)s);
	i = 0;
	start = 0;
	end = 0;
	while (42)
	{
		if (s[end] == '\n' || s[end] == '\0')
		{
			out[i] = ft_substr(s, start, end - start);
			if (!out[i++])
				split_fail(data, out, (char *)s);
			if (s[end] == '\0')
				return (out);
			start = end + 1;
		}
		end++;
	}
}
