/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:13 by maabdull          #+#    #+#             */
/*   Updated: 2023/12/10 14:12:50 by maabdull         ###   ########.fr       */
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
		if ((num[i] == '0' || num[i] == '+' || num[i] == '-') && !digit_found)
			continue ;
		digit_found = 1;
		val[j++] = num[i];
	}
	return (val);
}

// Checks if the provided number is greater than INT_MAX
// Uses strcmp and strlen to check if the number is 10 characters long and the difference from strcmp is greater than 1
static int	is_long(char *num)
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
		return (1);
	return (0);
}

// Loops through the (string) array and compares the provided (string) num.
// If they are the same, return 1
static int	is_duplicate_string(char *num, char **arg_list)
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
				return (1);
			else
				instances_found++;
		}
		i++;
	}
	return (0);
}

static int	is_digit_string(char *num)
{
	int	i;

	if (!num)
		return (1);
	i = -1;
	while (num[++i])
	{
		if (ft_isdigit(num[i]) == 1)
			return (1);
	}
	return (0);
}

// static int	is_duplicate_num(int num, int *num_list)
// {
// }

static void	extract_num_list(char **arg_list)
{
	int	i;

	i = -1;
	// TODO: Leaks
	while (arg_list[++i])
		arg_list[i] = extract_num(arg_list[i]);
}

// Checks the arguments that are still in string format if they are valid and not duplicates
// Makes it easier for passing to atoi
int	check_args(char **argument_list)
{
	int	i;

	i = 0;
	extract_num_list(argument_list);
	while (argument_list[i])
	{
		if (is_long(argument_list[i]) || is_duplicate_string(argument_list[i],
				argument_list) || !is_digit_string(argument_list[i]))
			return (1);
		i++;
	}
	return (0);
}

// Convert each (string) num in the (string) array passed to an integer
// Returns an int array that is malloced
// TODO: Free wherever used.
static int	*convert_num_list(char **arg_list)
{
	int	i;
	int	*num_list;

	i = 0;
	// num_list = malloc(size * 4);
	num_list = NULL;
	while (arg_list[i])
	{
		// num_list[i] = ft_atoi(arg_list[i]);
		i++;
	}
	return (num_list);
}

int	main(int argc, char const *argv[])
{
	int		i;
	char	*arguments;
	char	**argument_list;
	int		x;
	int		list_size;

	// int	*stack_values;
	list_size = 0;
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
	// printf("%s\n", arguments);
	argument_list = ft_split(arguments, ' ');
	if (check_args(argument_list))
		return (ft_putstr_fd("Error\n", 2), 1);
	x = -1;
	convert_num_list(argument_list);
	// Add to int array
	while (argument_list[++x])
		printf("%d\n", ft_atoi(argument_list[x]));
	return (0);
}
