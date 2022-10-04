/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:02:32 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/04 12:30:09 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (lst == NULL)
		return ;
	next = (*lst)->next;
	while (next)
	{
		ft_lstdelone(*lst, del);
		*lst = next;
		next = (*lst)->next;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
