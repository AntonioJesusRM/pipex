/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:37:45 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/04/24 13:51:59 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cont;
	char	*str_s1;
	char	*str_s2;

	cont = 0;
	str_s1 = (char *) s1;
	str_s2 = (char *) s2;
	while (cont < n)
	{
		if (str_s1[cont] != str_s2[cont])
			return ((unsigned char)str_s1[cont] - (unsigned char)str_s2[cont]);
		cont++;
	}
	if (cont < n)
	{
		return ((unsigned char)str_s1[cont] - (unsigned char)str_s2[cont]);
	}
	return (0);
}
