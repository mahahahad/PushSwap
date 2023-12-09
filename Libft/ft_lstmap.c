/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:55:22 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/27 15:19:06 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Iterates over a list 'lst' and applies the function 'f'.
	// If this results in a non-value, the 'del' function is used to remove it
	// from the list
/// @param lst
	// The linked list to map
/// @param f
	// The function to apply to each node
/// @param del
	// The function to delete a node
/// @return
	// The new list containing nodes that have had the function 'f' applied to
	// them
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *save;
	t_list *lst_new;

	if (!lst || !f || !del)
		return (NULL);
	save = ft_lstnew(f(lst->content));
	if (!save)
		return (NULL);
	lst_new = save;
	lst = lst->next;
	while (lst)
	{
		save->next = ft_lstnew(f(lst->content));
		if (!save->next)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		save = save->next;
		lst = lst->next;
	}
	save->next = NULL;
	return (lst_new);
}
