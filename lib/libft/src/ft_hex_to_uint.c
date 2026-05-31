/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:42:36 by elie              #+#    #+#             */
/*   Updated: 2024/03/15 09:32:59 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

uint32_t	ft_hex_to_uint(const char *str)
{
	unsigned int	value;

	value = 0;
	while (ft_iswhitespace(*str))
		str++;
	while (*str && ft_ishex(*str))
	{
		if (ft_ishex(*str))
		{
			value *= 16;
			value += ft_get_hex_value(*str);
		}
		str++;
	}
	return (value);
}
