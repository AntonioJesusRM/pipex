/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:15:14 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/18 11:16:29 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char l)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, l);
		ft_put_hex(num % 16, l);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (l == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (l == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char l)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, l);
	return (ft_hex_len(num));
}
