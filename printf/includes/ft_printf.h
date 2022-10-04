/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:04:32 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/18 11:19:09 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		ft_num_len(unsigned	int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_printstr(char *str);
int		ft_printchar(const char l);
int		ft_format(const char l, va_list args);
int		ft_printf(char const *str, ...);
int		ft_print_ptr(unsigned long long ptr);
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);
int		ft_printnbr(int n);
void	ft_putstr(char *str);
int		ft_hex_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char l);
int		ft_print_hex(unsigned int num, const char l);
int		ft_printpercent(void);
#endif