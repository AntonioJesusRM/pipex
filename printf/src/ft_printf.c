/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:18:35 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/18 11:20:04 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printchar(const char l)
{
	write (1, &l, 1);
	return (1);
}

int	ft_format(const char l, va_list args)
{
	int	cont;

	cont = 0;
	if (l == 'c')
		cont = cont + ft_printchar(va_arg(args, int));
	else if (l == 's')
		cont = cont + ft_printstr(va_arg(args, char *));
	else if (l == 'p')
		cont = cont + ft_print_ptr(va_arg(args, unsigned long long));
	else if (l == 'd' || l == 'i')
		cont = cont + ft_printnbr(va_arg(args, int));
	else if (l == 'u')
		cont = cont + ft_print_unsigned(va_arg(args, unsigned int));
	else if (l == 'x' || l == 'X')
		cont = cont + ft_print_hex(va_arg(args, unsigned int), l);
	else if (l == '%')
		cont = cont + ft_printpercent();
	return (cont);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		j;
	va_list	args;
	int		cont;

	i = 0;
	j = 0;
	cont = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			cont = cont + ft_printchar(str[i]);
		else
		{
			i++;
			cont = cont + ft_format (str[i], args);
		}
		i++;
	}
	va_end(args);
	return (cont);
}
