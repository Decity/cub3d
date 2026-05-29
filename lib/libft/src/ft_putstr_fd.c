/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:19:08 by ebayat            #+#    #+#             */
/*   Updated: 2024/02/11 11:40:31 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	len;

	if (!str)
		return (write(fd, "(null)", ft_strlen("(null)")));
	len = ft_strlen(str);
	if (len)
		return (write(fd, str, len));
	return (0);
}
