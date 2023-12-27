/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:13 by maabdull          #+#    #+#             */
/*   Updated: 2023/12/10 17:00:38 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	print_arr(const char **arr, int len)
{
	for (int i = 1; i < len; ++i)
	{
		print_str(arr[i]);
		print_str(" ");
	}
}

// Remove unnecessary values from the number such as leading zeros and signs
// Return the extracted number or NULL if invalid number is passed
static char	*extract_num(char *num)
{
	int		i;
	int		j;
	int		digit_found;
	char	*val;

	i = -1;
	j = 0;
	digit_found = 0;
	// TODO: Free this wherever called
	val = malloc(ft_strlen(num) + 1);
	while (num[++i])
	{
		if ((num[i] == '0' && num[i + 1] != '\0') && !digit_found)
			continue ;
		if (num[i] == '-')
		{
			val[j++] = num[i];
			continue;
		}
		if ((num[i] == '+') && digit_found)
			break ;
		digit_found = 1;
		val[j++] = num[i];
	}
	if (!digit_found)
		return (NULL);
	return (val);
}

// Checks if the provided number is greater than INT_MAX
// Uses strcmp and strlen to check if the number is 10 characters long and the difference from strcmp is greater than 1
static bool	is_long(char *num)
{
	char	*max_int;
	int		res;

	if (num[0] == '-')
		max_int = "-2147483648";
	else
		max_int = "2147483647";
	res = ft_strcmp(num, max_int);
	if ((res > 0 && ft_strlen(num) == 10) || (num[0] == '-'
			&& ft_strlen(num) > 11) || (num[0] != '-' && ft_strlen(num) > 10))
		return (true);
	return (false);
}

// Loops through the (string) array and compares the provided (string) num.
// If they are the same, return 1
static bool	is_duplicate_string(char *num, char **arg_list)
{
	int	i;
	int	instances_found;

	i = 0;
	instances_found = 0;
	while (arg_list[i])
	{
		if (ft_strcmp(num, arg_list[i]) == 0)
		{
			if (instances_found >= 1)
				return (true);
			else
				instances_found++;
		}
		i++;
	}
	return (false);
}

static bool	extract_num_list(char **arg_list)
{
	int	i;

	i = -1;
	// TODO: Leaks
	while (arg_list[++i])
	{
		arg_list[i] = extract_num(arg_list[i]);
		if (arg_list[i] == NULL)
			return (false);
	}
	return (true);
}

// Checks the arguments that are still in string format if they are valid and not duplicates
// Makes it easier for passing to atoi
static bool	are_args_valid(char **argument_list, int *size)
{
	int	i;

	i = 0;
	if (!extract_num_list(argument_list))
		return (false);
	while (argument_list[i])
	{
		if (is_long(argument_list[i]) || is_duplicate_string(argument_list[i],
				argument_list))
			return (false);
		i++;
	}
	*size = i;
	return (true);
}

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

t_list *create_node(int num)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->next = NULL;
	new->prev = NULL;
	new->data = num;
	return (new);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d", head->data);
		if (head->next)
			printf(", ");
		head = head->next;
	}
	puts("");
}

t_list	 *ra(t_list *stack_head)
{
	int	data;
	t_list	*temp;

	temp = stack_head;
	data = stack_head->data;
	while (stack_head->next)
	{
		stack_head->data = stack_head->next->data;
		stack_head = stack_head->next;
	}
	stack_head->data = data;
	stack_head = temp;
	printf("ra\n");
	return (stack_head);
}

bool	is_sorted(t_list *head)
{
	while (head->next)
	{
		if (head->data > head->next->data)
			return (false);
		head = head->next;
	}
	return (true);
}

int	main(int argc, char const *argv[])
{
	int		i;
	char	*arguments;
	char	**argument_list;
	int		x;
	int		*arr;
	t_list	*stack_a;
	int	size;

	stack_a = NULL;
	arr = NULL;
	arguments = malloc(1);
	i = 1;
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
		return (ft_putstr_fd("Error\n", 2), 1);
	x = -1;
	while (argument_list[++x])
		stack_a = append_to_node(stack_a, create_node(ft_atoi(argument_list[x])));
	if (is_sorted(stack_a))
		return (0);
	if (size == 2)
		stack_a = ra(stack_a);
	print_list(stack_a);
	return (0);
}
