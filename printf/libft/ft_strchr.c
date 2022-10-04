/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:37:04 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/04/24 11:14:00 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cont;
	char	*ptr;

	ptr = "\0";
	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
		{
			ptr = (char *)&s[cont];
			return (ptr);
		}
		cont ++;
	}
	if (c == '\0')
		return ((char *)&s[cont]);
	return (0);
}
