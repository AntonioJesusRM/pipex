/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:12:24 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/04 16:29:17 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] == '\t' || str[cont] == '\n' || str[cont] == '\v'
			|| str[cont] == '\f' || str[cont] == '\r' || str[cont] == ' ')
			cont++;
		else
			return (cont);
	}
	return (cont);
}

int	ft_atoi(const char *str)
{
	int	cont;
	int	num;
	int	sig;

	cont = ft_space(str);
	num = 0;
	sig = 1;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			sig = sig * (-1);
		cont++;
	}
	while (str[cont] != '\0')
	{
		if (str[cont] >= '0' && str[cont] <= '9')
			num = (num * 10) + (str[cont] - '0');
		else
			return (num * sig);
		cont++;
	}
	return (num * sig);
}
