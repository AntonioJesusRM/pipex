/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:49:03 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/04 16:22:25 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str_dst;
	char	*str_src;
	size_t	cont;

	str_dst = (char *) dst;
	str_src = (char *) src;
	cont = 0;
	if (str_dst == (void *)0 && str_src == (void *)0)
		return (0);
	while (cont < n)
	{
		str_dst[cont] = str_src[cont];
		cont ++;
	}
	dst = (void *) str_dst;
	return (dst);
}
