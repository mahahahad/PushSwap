/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:13 by maabdull          #+#    #+#             */
/*   Updated: 2023/12/09 17:06:42 by maabdull         ###   ########.fr       */
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

// Checks if the provided number is greater than INT_MAX
// Uses strcmp and strlen to check if the number is 10 characters long and the difference from strcmp is greater than 1
static int 	is_long(char *num)
{
	char *max_int;
	int res;

	if (num[0] == '-')
		max_int = "-2147483648";
	else
		max_int = "2147483647";
	res = ft_strcmp(num, max_int);
	if ((res > 0 && ft_strlen(num) == 10) \
		|| (num[0] == '-' && ft_strlen(num) > 11) \
		|| (num[0] != '-' && ft_strlen(num) > 10))
		return (print_str("Error"), print_str("Only integers are allowed"), 1);
	return (0);
}

// Loops through the array and compares the provided num. If they are the same, return 1
static int 	is_duplicate(char *num, char **arg_list)
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
				return (print_str("Error"), print_str("No duplicates allowed"), 1);
			else
				instances_found++;
		}
		i++;
	}
	return (0);
}
// Checks the arguments that are still in string format if they are valid and not duplicates
// Makes it easier for passing to atoi
int	check_args(char **argument_list)
{
	int	i;

	i = 0;
	while (argument_list[i])
	{
		if (is_long(argument_list[i]) || is_duplicate(argument_list[i], argument_list))
			return (1);
		i++;
	}
	return (0);
}

// Loop through each argument in the argument vector
// If it contains a space, split it at that space
// Add each string to an array
// Loop through the array and convert each string to an int
// Add this int to the stacks linked list
/*
According to Tanvir:
STRJOIN everything into one string and then split it later
*/
int	main(int argc, char const *argv[])
{
	int	i;
	char  *arguments;
	char  **argument_list;
	int x;

	// int	*stack_values;
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
	printf("%s\n", arguments);
	argument_list = ft_split(arguments, ' ');
	if (check_args(argument_list))
		return (1);
	x = 0;
	while (argument_list[x])
	{
		// puts(argument_list[x]);
		printf("%d\n", ft_atoi(argument_list[x]));
		x++;
	}
	return (0);
}
