/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:11:00 by elie              #+#    #+#             */
/*   Updated: 2026/06/09 11:11:46 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/** @brief Initializes the t_data struct */
void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->map.floor_color = -1;
	data->map.ceiling_color = -1;
}
