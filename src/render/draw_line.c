/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:16:20 by crabin            #+#    #+#             */
/*   Updated: 2026/06/12 19:18:08 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_h_line(t_mlx *mlx, t_ivec2 p, int len, int colour)
{
	int	i;
	int	step;

	i = 0;
	step = 1;
	if (len < 0)
		step = -1;
	while (i != len + step)
	{
		set_pixel(mlx, p.x + i, p.y, colour);
		i += step;
	}
}
