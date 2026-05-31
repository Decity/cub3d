/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:22:23 by crabin            #+#    #+#             */
/*   Updated: 2026/05/30 20:30:26 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

bool in_bounds(int x, int y, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (false);
	return (true);
}

bool is_wall(int x, int y, t_map *map)
{
	if (!in_bounds(x, y, map))
		return (true);
	
	if (map->grid[y][x] == WALL)
		return (true);
	return (false);
}
