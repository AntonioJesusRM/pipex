/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:27:17 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/05/04 12:29:26 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	node = new_lst;
	while (lst->next)
	{
		node->next = ft_lstnew(f(lst->next->content));
		if (node->next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	return (new_lst);
}
