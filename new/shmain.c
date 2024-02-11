/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:00:32 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/11 21:22:10 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	if (is_sorted(*stack_a, *stack_b))
		return (0);
	if (size == 2)
		ra(stack_a);
	if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b, size);
	else
		sort_radix(stack_a, stack_b, size);
	return (0);
}

// Join the arguments to be seperated by spaces
// Split the arguments by spaces
// Validate each number
// Convert each number to integer and store in an array
// Sort this array and assign each integer a rank
// Create a stack for each node with their respective rank and data
int	main(int argc, char *argv[])
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	arguments = NULL;
	size = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	arguments = process_args(argv, &size);
	validate_args(arguments);
	stack_a = create_stack(arguments, size);
	free_args(arguments);
	push_swap(&stack_a, &stack_b, size);
	free_stack(stack_a);
	return (0);
}
