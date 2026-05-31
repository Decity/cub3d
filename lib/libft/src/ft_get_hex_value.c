/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:47:04 by elie              #+#    #+#             */
/*   Updated: 2024/03/14 18:58:34 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

unsigned int	ft_get_hex_value(int c)
{
	char	*hex_val;
	int		i;

	i = 0;
	hex_val = HEX_BASE;
	while (hex_val[i] && hex_val[i] != ft_toupper(c))
		i++;
	return (i);
}
