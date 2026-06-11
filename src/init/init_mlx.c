/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:34:38 by elie              #+#    #+#             */
/*   Updated: 2026/06/11 15:49:19 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx.p_mlx = mlx_init();
	if (!data->mlx.p_mlx)
		error_exit(data, "mlx_init failed");
	data->mlx.win = mlx_new_window(data->mlx.p_mlx, WINDOW_W, WINDOW_H,
			"cub3D");
	if (!data->mlx.win)
		error_exit(data, "mlx_new_window failed");
	data->mlx.screen.img_pointer = mlx_new_image(data->mlx.p_mlx, WINDOW_W, WINDOW_H);
	if (!data->mlx.screen.img_pointer)
		error_exit(data, "mlx_new_image failed");
	data->mlx.screen.addr = mlx_get_data_addr(
			data->mlx.screen.img_pointer,
			&data->mlx.screen.bit_pp,
			&data->mlx.screen.line_len,
			&data->mlx.screen.endian
			);
	if (!data->mlx.screen.addr)
		error_exit(data, "mlx_get_data_addr failed");
}

