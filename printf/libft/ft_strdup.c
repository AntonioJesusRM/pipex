/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:17:14 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/18 09:21:55 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*out;

	i = 0;
	len = ft_strlen(s1);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
