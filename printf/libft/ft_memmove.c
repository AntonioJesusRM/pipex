/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:54:04 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/04/26 08:31:23 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*str_dst;
	unsigned const char	*str_src;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	str_dst = (unsigned char *) dst;
	str_src = (unsigned const char *) src;
	if (!len || dst == src)
		return (dst);
	while (len --)
	{
		str_dst[len] = str_src[len];
	}
	return (dst);
}
