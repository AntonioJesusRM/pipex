/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:37:42 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/09/21 12:36:06 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		cont;
	int		cont2;

	cont = 0;
	cont2 = 0;
	if (!s1)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!str)
		return (NULL);
	while (s1[cont] != '\0')
	{
		str[cont] = s1[cont];
		cont ++;
	}
	while (s2[cont2] != '\0')
	{
		str[cont] = s2[cont2];
		cont ++;
		cont2 ++;
	}
	str[cont] = '\0';
	return (str);
}
