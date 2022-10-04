/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:38:24 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/04/26 09:36:34 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cont;

	cont = 0;
	if (dstsize > 0)
	{
		while (dstsize - 1 > cont && src[cont])
		{
			dst[cont] = src[cont];
			cont ++;
		}
		dst[cont] = '\0';
	}
	return (ft_strlen(src));
}
