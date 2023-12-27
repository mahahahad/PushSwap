/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:31:01 by maabdull          #+#    #+#             */
/*   Updated: 2023/12/27 11:36:54 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_three(t_list *head)
{
	
}

t_list	 *ra(t_list *head)
{
	int	data;
	t_list	*stack_head;

	stack_head = head;
	data = head->data;
	while (head->next)
	{
		head->data = head->next->data;
		head = head->next;
	}
	head->data = data;
	head = stack_head;
	printf("ra\n");
	return (head);
}
