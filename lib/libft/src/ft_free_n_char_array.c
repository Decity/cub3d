/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_n_char_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:33:48 by elie              #+#    #+#             */
/*   Updated: 2024/05/16 15:36:06 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_n_char_array(size_t n, char **array)
{
	while (n--)
	{
		free(array[n]);
		array[n] = NULL;
	}
	free(array);
	array = NULL;
}
