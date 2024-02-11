/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:01:17 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/11 19:53:05 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Push the minimum value from the first stack to the second stack
static void	push_min(t_list **head_a, t_list **head_b)
{
	static int	rank;

	while ((*head_a)->next)
	{
		if ((*head_a)->rank == rank)
		{
			push(head_a, head_b);
			break ;
		}
		ra(head_a);
	}
	rank++;
}

// Sorts a stack with EXACTLY TWO NUMBERS to be in descending order
static void	descend_sort(t_list **head)
{
	if ((*head)->next && ((*head)->data < (*head)->next->data))
		swap(head);
}

static void	push_all_to_a(t_list **head_a, t_list **head_b)
{
	while ((*head_b))
		push(head_b, head_a);
}

t_list	**sort_five(t_list **head_a, t_list **head_b, int size)
{
	if (size == 5)
		push_min(head_a, head_b);
	push_min(head_a, head_b);
	descend_sort(head_b);
	sort_three(head_a);
	push_all_to_a(head_a, head_b);
	return (head_a);
}
