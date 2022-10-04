/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:02:57 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/04/26 12:33:41 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cont;
	size_t	cont2;

	cont = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	while (haystack[cont] != '\0' && cont < len)
	{
		cont2 = 0;
		while (haystack[cont + cont2] == needle[cont2] && cont + cont2 < len)
		{
			if (needle[cont2 + 1] == '\0')
				return ((char *)haystack + cont);
			cont2++;
		}
		cont++;
	}
	return (NULL);
}
