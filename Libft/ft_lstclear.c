/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:55:07 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/27 15:25:27 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Deletes each element in the linked list 'lst' using the function 'del'
	// and returns a pointer to NULL
/// @param lst
	// The linked list to delete
/// @param del
	// The function to delete using
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (!lst || !del)
		return ;
	prev = (*lst);
	while (*lst)
	{
		(*lst) = (*lst)->next;
		ft_lstdelone(prev, del);
		prev = *lst;
	}
	*lst = NULL;
}
