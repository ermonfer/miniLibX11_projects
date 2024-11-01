/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:52:57 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/02 20:26:24 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*node;
	t_list		*new_lst;

	new_lst = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(lst->content);
		if (node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		node->content = f(node->content);
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
