/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:16:37 by crabin            #+#    #+#             */
/*   Updated: 2026/06/05 17:55:02 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

char *get_pix_texture(t_texture *t, int x, int y)
{
	return (t->addr + (t->byt_pp * x) + (t->line_len * y));
}

unsigned int get_colour_texture(t_texture *t, int x, int y)
{
	char *pixel;

	pixel = get_pix_texture(t, x, y);
	return (*(unsigned int *)pixel);
}



void put_col_texture(t_data *data, t_texture *t, t_column *c)
{
	double scale;
	int relative_y;
	int	i;
	t_mlx *mlx;
	int		colour;

	scale = t->height / c->len;
	i = 0;
	mlx = &data->mlx;
	while (c->start.y + i < 0)
		i++;
	while (i < c->len)
	{
		colour = get_colour_texture(
				t, 
				(int)(t->width * c->hit_pos), 
				(int)(i * scale)
			);
		set_pixel(mlx, c->start.x, c->start.y + i, colour);
		i++;
	}
}