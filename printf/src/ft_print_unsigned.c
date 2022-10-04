/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:38:54 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/18 11:08:18 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		cont;

	cont = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (cont + 1));
	if (!num)
		return (0);
	num[cont] = '\0';
	while (n != 0)
	{
		num[cont - 1] = n % 10 + 48;
		n = n / 10;
		cont--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		cont;
	char	*num;

	cont = 0;
	if (n == 0)
		cont = cont + write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		cont = cont + ft_printstr(num);
		free(num);
	}
	return (cont);
}
