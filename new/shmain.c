#include "../push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_radix(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}

// Join the arguments to be seperated by spaces
// Split the arguments by spaces
// Validate each number
// Convert each number to integer and store in an array
// Sort this array and assign each integer a rank
// Create a stack for each node with their respective rank and data
int main(int argc, char *argv[])
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*stack_b;
	int	size;
	int	i;

	i = 0;
	arguments = NULL;
 	size = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	arguments = process_args(argv, &size);
	validate_args(arguments);
	stack_a = create_stack(arguments);
	free_args(arguments);
	push_swap(&stack_a, &stack_b, size);
	return (0);
}