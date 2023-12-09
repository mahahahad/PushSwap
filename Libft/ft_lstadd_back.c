/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:54:28 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/27 15:24:10 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Adds a node 'new' to the end of the linked list 'lst'
/// @param lst
	// The linked list to change
/// @param new
	// The new node to add
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*(lst))
	{
		last = ft_lstlast(*(lst));
		last->next = new;
	}
	else
		*lst = new;
}
