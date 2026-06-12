/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:18:32 by crabin            #+#    #+#             */
/*   Updated: 2026/06/12 19:21:06 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_box(t_mlx *mlx, t_ivec2 origin, t_ivec2 size, int colour)
{
	int	i;

	i = 0;
	while (i < size.y)
	{
		draw_h_line(mlx, origin, size.x, colour);
		origin.y++;
		i++;
	}
}

int	render(t_data *data)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	clear_mlx_buff(mlx);
	draw_floor_ceiling(data);
	cast_rays(data);
	mlx_put_image_to_window(
		mlx->p_mlx, mlx->win, mlx->screen.img_pointer, 0, 0);
	draw_fps(data);
	return (SUCCESS);
}
