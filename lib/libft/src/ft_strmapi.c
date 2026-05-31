/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:58:34 by elie              #+#    #+#             */
/*   Updated: 2024/02/09 17:41:39 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cstr;

	i = 0;
	cstr = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!cstr || !s || !f)
		return (NULL);
	while (s[i])
	{
		cstr[i] = f(i, (char)s[i]);
		i++;
	}
	return (cstr);
}
