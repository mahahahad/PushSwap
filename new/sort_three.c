/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:01:22 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/11 19:48:16 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	compare(t_list **head, int first, int second, int third)
{
	if (first > second && first > third)
	{
		if (second > third)
		{
			swap(head);
			rra(head);
		}
		else
			ra(head);
	}
	else if (second > first && second > third)
	{
		if (third > first)
		{
			swap(head);
			ra(head);
		}
		else
			rra(head);
	}
	else
		swap(head);
}

t_list	**sort_three(t_list **head)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*head, NULL))
		return (head);
	first = (*head)->data;
	second = (*head)->next->data;
	third = (*head)->next->next->data;
	compare(head, first, second, third);
	return (head);
}
