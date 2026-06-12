/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:20:17 by crabin            #+#    #+#             */
/*   Updated: 2026/06/12 19:21:15 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	char_to_color(char c)
{
	if (c == '1')
		return (COLOR_WALL);
	if (c == '0')
		return (COLOR_FLOOR);
	return (COLOR_BLACK);
}

static void	draw_tile(t_data *data, int x, int y, int color)
{
	int	px;
	int	py;

	py = 0;
	while (py < TILE_SIZE)
	{
		px = 0;
		while (px < TILE_SIZE)
		{
			set_pixel(&data->mlx, x + px, y + py, color);
			px++;
		}
		py++;
	}
}

static void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			draw_tile(data, x * TILE_SIZE, y * TILE_SIZE,
				char_to_color(data->map.grid[y * data->map.width + x]));
			x++;
		}
		y++;
	}
}

static void	draw_player(t_data *data)
{
	draw_tile(data, data->player.pos.x * TILE_SIZE,
		data->player.pos.y * TILE_SIZE, COLOR_PLAYER);
}

static void	draw_dir(t_data *data)
{
	int			line_start[2];
	int			line_end[2];
	t_player	player;

	player = data->player;
	line_start[0] = player.pos.x * TILE_SIZE + TILE_SIZE / 2;
	line_start[1] = player.pos.y * TILE_SIZE + TILE_SIZE / 2;
	line_end[0] = (player.pos.x + player.dir.x) * TILE_SIZE + TILE_SIZE / 2;
	line_end[1] = (player.pos.y + player.dir.y) * TILE_SIZE + TILE_SIZE / 2;
	draw_line(data, line_start, line_end, COLOR_WHITE);
}
