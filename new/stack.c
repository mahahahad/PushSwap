/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:01:29 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/11 21:22:34 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*compare(int *arr_sorted, int *arr, int size, int *max)
{
	int	i;
	int	j;
	int	*ranks;

	i = 0;
	j = 0;
	ranks = malloc(size * sizeof(int));
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr_sorted[j] == arr[i])
				ranks[i] = j;
			j++;
		}
		i++;
	}
	*max = arr_sorted[size - 1];
	return (ranks);
}

int	*convert_to_int(char **arguments, int size)
{
	int	i;
	int	*arr;

	i = -1;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (free(arr), free_args(arguments), show_err(), NULL);
	while (arguments[++i])
		arr[i] = ft_atoi(arguments[i]);
	return (arr);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	temp;

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
}

int	*assign_ranks(char **arg_list, int size, int *max)
{
	int	*arr_sorted;
	int	*arr_original;
	int	*temp_arr;

	temp_arr = NULL;
	arr_original = convert_to_int(arg_list, size);
	arr_sorted = convert_to_int(arg_list, size);
	sort_arr(arr_sorted, size);
	temp_arr = arr_sorted;
	arr_sorted = compare(arr_sorted, arr_original, size, max);
	free(temp_arr);
	free(arr_original);
	return (arr_sorted);
}

/*
Creates a stack with the provided arguments which is done by:
- Sorting the arguments list
- Comparing each argument to its position in the sorted array
- Assigning a rank to each argument
- And finally, creating the stack with these ranks and integer values
*/
t_list	*create_stack(char **arguments, int size)
{
	int		i;
	int		max;
	int		*ranks;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	max = 0;
	ranks = assign_ranks(arguments, size, &max);
	while (arguments[i])
	{
		stack_a = append_to_node(stack_a, create_node(ft_atoi(arguments[i]), \
								ranks[i]));
		i++;
	}
	free(ranks);
	stack_a->max = max;
	return (stack_a);
}
