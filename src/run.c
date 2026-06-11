/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:29:54 by elie              #+#    #+#             */
/*   Updated: 2026/06/09 11:40:40 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	run(t_data *data)
{
	render(data);
	mlx_hook(data->mlx.win, 2, 1L << 0, (int (*)())(void *)on_key, data);
	mlx_hook(data->mlx.win, 17, 0, (int (*)())(void *)close_window, data);
	mlx_loop_hook(data->mlx.p_mlx, (int (*)())(void *)render, data);
	mlx_loop(data->mlx.p_mlx);
	return (EXIT_SUCCESS);
}
