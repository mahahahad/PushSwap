/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:13 by maabdull          #+#    #+#             */
/*   Updated: 2024/01/22 17:20:54 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.c"
#include "push_swap.h"

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
	return (new);
}

bool	is_sorted(t_list *head, t_list *head_b)
{
	if (head_b)
		return (false);
	while (head->next)
	{
		if (head->data > head->next->data)
			return (false);
		head = head->next;
	}
	return (true);
}

t_list	*sort_three(t_list *head)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(head, NULL))
		return (head);
	first = head->data;
	second = head->next->data;
	third = head->next->next->data;
	if (first > second && first > third)
	{
		if (second > third)
		{
			head = sa(head);
			head = rra(head);
		}
		else
			ra(&head);
	}
	else if (second > first && second > third)
	{
		if (third > first)
		{
			head = sa(head);
			ra(&head);
		}
		else
			head = rra(head);
	}
	else
		head = sa(head);
	return (head);
}

int	*compare(int *arr_sorted, int *arr, int size, int *max)
{
	int	i;
	int	j;
	int	*ranks;
	int	highest;

	i = 0;
	j = 0;
	ranks = malloc(size * sizeof(int));
	highest = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr_sorted[j] == arr[i])
				ranks[i] = j;
			if (highest < ranks[i])
				highest = ranks[i];
			j++;
		}
		i++;
	}
	*max = highest;
	return (ranks);
}

int	*sort_arr(char **arg_list, int size, int *max)
{
	int	i;
	int	*arr;
	int	*arr_copy;
	int	temp;

	i = -1;
	arr = malloc(size * sizeof(int));
	arr_copy = malloc(size * sizeof(int));
	while (arg_list[++i])
	{
		arr[i] = ft_atoi(arg_list[i]);
		arr_copy[i] = ft_atoi(arg_list[i]);
	}
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	arr = compare(arr, arr_copy, size, max);
	return (arr);
}

void	push_all_to_a(t_list **head_a, t_list **head_b)
{
	while ((*head_b))
		push(head_b, head_a);
}

bool	is_stack_empty(t_list **stack)
{
	if ((*stack) != NULL)
		return (false);
	return (true);
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

t_list	**sort_radix(t_list **head_a, t_list **head_b, int size, int max)
{
	int	i;
	int	shift;
	int	shift_limit;

	i = 0;
	shift = 0;
	shift_limit = get_bits(max);
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
// Push the minimum value from the first stack to the second stack
static void	push_min(t_list **head_a, t_list **head_b)
{
	while ((*head_a)->next)
	{
		if ((*head_a)->rank == 0 || (*head_a)->rank == 1)
		{
			push(head_a, head_b);
			break ;
		}
		ra(head_a);
	}
}

// Sorts a stack with EXACTLY TWO NUMBERS to be in descending order
static void	descend_sort(t_list **head)
{
	if ((*head)->data < (*head)->next->data)
		swap(head);
}

t_list	**sort_five(t_list **head_a, t_list **head_b)
{
	push_min(head_a, head_b);
	push_min(head_a, head_b);
	descend_sort(head_b);
	*head_a = sort_three(*head_a);
	push_all_to_a(head_a, head_b);
	return (head_a);
}

int	main(int argc, char const *argv[])
{
	int		i;
	char	*arguments;
	char	**argument_list;
	int		x;
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	int		*ranks;
	int		max;

	stack_a = NULL;
	stack_b = NULL;
	ranks = NULL;
	arguments = malloc(1);
	i = 1;
	max = 0;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		// TODO: LEAKS
		arguments = ft_strjoin(arguments, ft_strjoin(" ", argv[i]));
		i++;
	}
	argument_list = ft_split(arguments, ' ');
	if (!are_args_valid(argument_list, &size))
		return (ft_putendl_fd("Error", 2), 1);
	x = -1;
	ranks = sort_arr(argument_list, size, &max);
	// print_int_arr(ranks, size);
	while (argument_list[++x])
		stack_a = append_to_node(stack_a, create_node(ft_atoi(argument_list[x]),
				ranks[x]));
	if (is_sorted(stack_a, stack_b))
		return (0);
	if (size == 2)
		ra(&stack_a);
	else if (size == 3)
		stack_a = sort_three(stack_a);
	else if (size <= 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_radix(&stack_a, &stack_b, size, max);
	print_list(stack_a);
	return (0);
}
