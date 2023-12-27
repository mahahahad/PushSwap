/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:31:01 by maabdull          #+#    #+#             */
/*   Updated: 2023/12/27 14:30:09 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap
// Swap the first two numbers from the stack
t_list	 *sa(t_list *head)
{
	int	data;

	data = head->data;
	head->data = head->next->data;
	head->next->data = data;
	printf("sa\n");
	return (head);
}

// Reverse Rotate
// Move the bottom number from the stack to the top
t_list	 *rra(t_list *head)
{
	int	data;

	while (head->next)
		head = head->next;
	data = head->data;
	while (head->prev)
	{
		head->data = head->prev->data;
		head = head->prev;
	}
	head->data = data;
	printf("rra\n");
	return (head);
}

// Rotate
// Move the top number of the stack to the bottom
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
