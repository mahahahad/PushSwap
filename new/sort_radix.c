/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:00:41 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/11 21:24:49 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_all_to_a(t_list **head_a, t_list **head_b)
{
	while ((*head_b))
		push(head_b, head_a);
}

static int	get_bits(int max)
{
	int	bits;

	bits = 0;
	while (max)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

t_list	**sort_radix(t_list **head_a, t_list **head_b, int size)
{
	int	i;
	int	shift;
	int	shift_limit;

	i = 0;
	shift = 0;
	shift_limit = get_bits((*head_a)->max);
	while (i < size && !is_sorted(*head_a, *head_b))
	{
		if ((*head_a)->rank & (1 << shift))
			ra(head_a);
		else
			push(head_a, head_b);
		i++;
		if (i == size)
		{
			push_all_to_a(head_a, head_b);
			if (shift != shift_limit)
			{
				i = 0;
				shift++;
			}
		}
	}
	return (head_a);
}
