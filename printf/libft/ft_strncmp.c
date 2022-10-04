/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:22:48 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/04/24 13:50:52 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cont;

	cont = 0;
	while (s1[cont] != '\0' && s2[cont] != '\0' && cont < n)
	{
		if (s1[cont] != s2[cont])
		{
			return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		}
		cont ++;
	}
	if (cont < n)
	{
		return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
	}
	return (0);
}
