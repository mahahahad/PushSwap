/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:31:01 by maabdull          #+#    #+#             */
/*   Updated: 2024/01/22 17:23:38 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap
// Swap the first two numbers from the stack
t_list	*sa(t_list *head)
{
	int	data;

	data = head->data;
	head->data = head->next->data;
	head->next->data = data;
	ft_putendl_fd("sa", 1);
	return (head);
}

void	swap(t_list **head)
{
	int	data;

	data = (*head)->data;
	(*head)->data = (*head)->next->data;
	(*head)->next->data = data;
	if ((*head)->stack_name == 'A')
		ft_putendl_fd("sa", 1);
	else
		ft_putendl_fd("sb", 1);
}

// Reverse Rotate
// Move the bottom number from the stack to the top
t_list	*rra(t_list *head)
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
	ft_putendl_fd("rra", 1);
	return (head);
}

// Rotate
// Move the top number of the stack to the bottom
void	ra(t_list **stack_head)
{
	t_list	*temp;
	t_list	*head;

	temp = *stack_head;
	*stack_head = (*stack_head)->next;
	head = *stack_head;
	while (head->next)
		head = head->next;
	temp->prev = head;
	temp->next = NULL;
	head->next = temp;
	ft_putendl_fd("ra", 1);
}

static t_list	*push_to_stack(t_list *head, t_list *node)
{
	if (!head)
		return (node);
	node->next = head;
	head->prev = node;
	head = head->prev;
	return (head);
}

void	push(t_list **first_stack, t_list **second_stack)
{
	t_list	*temp;

	temp = *first_stack;
	*first_stack = temp->next;
	if (*first_stack)
		(*first_stack)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	if (temp->stack_name == 'A')
	{
		ft_putendl_fd("pb", 1);
		temp->stack_name = 'B';
	}
	else
	{
		ft_putendl_fd("pa", 1);
		temp->stack_name = 'A';
	}
	*second_stack = push_to_stack(*second_stack, temp);
}
