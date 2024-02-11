/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:01:27 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/11 19:56:24 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*append_to_node(t_list *head, t_list *node)
{
	t_list	*temp;

	if (!head)
		return (node);
	temp = head;
	while (head->next)
		head = head->next;
	node->prev = head;
	head->next = node;
	head = temp;
	return (head);
}

t_list	*create_node(int num, int rank)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->next = NULL;
	new->prev = NULL;
	new->rank = rank;
	new->data = num;
	new->stack_name = 'A';
	new->max = 0;
	return (new);
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%d", stack->data);
		if (stack->next)
			printf(", ");
		else
			puts("");
		stack = stack->next;
	}
}
