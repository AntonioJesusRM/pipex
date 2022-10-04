/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:24:55 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/18 11:18:31 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	cont;

	cont = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[cont])
	{
		write (1, &str[cont], 1);
		cont++;
	}
	return (cont);
}

int	ft_printnbr(int n)
{
	int		cont;
	char	*num;

	cont = 0;
	num = ft_itoa(n);
	cont = ft_printstr(num);
	free (num);
	return (cont);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
