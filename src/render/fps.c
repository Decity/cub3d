/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:36:03 by elie              #+#    #+#             */
/*   Updated: 2026/06/10 16:36:04 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

/**
 * @brief updates the fps struct
 * 
 * Counts the frames that have occurred over ~1 second
 */
static void	update_fps(t_fps *fps)
{
	long	now;
	long	elapsed;

	fps->frames++;
	now = get_current_time();
	if (fps->last_ms == 0)
		fps->last_ms = now;
	elapsed = now - fps->last_ms;
	if (elapsed >= ONE_SECOND_IN_MS)
	{
		fps->display_value = (int)(fps->frames * 1000 / elapsed);
		fps->frames = 0;
		fps->last_ms = now;
	}
}

/**
 * @brief Draws "FPS: x" on the top left corner of the window
 * 
 * When called, it updates the fps struct, then grabs the value to display,
 * and displays it with mlx_string_put().
 */
void	draw_fps(t_data *data)
{
	char	*num;
	char	*text;

	update_fps(&data->fps);
	num = ft_itoa(data->fps.display_value);
	if (!num)
		return ;
	text = ft_strjoin("FPS: ", num);
	free(num);
	if (!text)
		return ;
	mlx_string_put(data->mlx.p_mlx, data->mlx.win, 10, 20, COLOR_GREEN, text);
	free(text);
}
