/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:16:24 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/04/24 11:19:15 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cont;
	int		loc;
	char	*ptr;

	ptr = "\0";
	cont = 0;
	loc = -1;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
		{
			loc = cont;
		}
		cont ++;
	}
	if (c == '\0')
		return ((char *)&s[cont]);
	else if (loc != -1)
	{
		ptr = (char *)&s[loc];
		return (ptr);
	}
	return (0);
}
