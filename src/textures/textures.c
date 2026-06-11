/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:16:37 by crabin            #+#    #+#             */
/*   Updated: 2026/06/11 15:53:00 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

char *get_pix_texture(t_texture *t, int x, int y)
{
	return (t->img.addr + (t->img.byt_pp * x) + (t->img.line_len * y));
}

unsigned int get_colour_texture(t_texture *t, int x, int y)
{
	char *pixel;

	pixel = get_pix_texture(t, x, y);
	return (*(unsigned int *)pixel);
}

void put_col_texture(t_data *data, t_texture *t, t_column *c)
{
	double	scale;
	int		i;
	t_mlx	*mlx;
	int		colour;

	mlx = &data->mlx;
	scale = (double)t->img.height / (double)c->len;
	if (scale < EPSILON)
		scale = EPSILON;
	i = 0;
	while (c->start.y + i < 0)
		i++;
	while (i < c->len)
	{
		colour = get_colour_texture(
				t, 
				(int)(t->img.width * c->hit_pos), 
				(int)(i * scale)
			);
		set_pixel(mlx, c->start.x, c->start.y + i, colour);
		i++;
	}
}