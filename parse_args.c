/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:59:51 by maabdull          #+#    #+#             */
/*   Updated: 2024/01/22 17:18:18 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	val = malloc(ft_strlen(num) + 1);
	while (num[++i])
	{
		if ((num[i] == '0' && num[i + 1] != '\0') && !digit_found)
			continue ;
		if (num[i] == '-' && !digit_found)
		{
			val[j++] = num[i];
			continue ;
		}
		if ((num[i] == '+' || num[i] == '-') && digit_found)
			return (NULL);
		digit_found = 1;
		val[j++] = num[i];
	}
	if (!digit_found)
		return (NULL);
	return (val);
}

// Checks if the provided number is greater than INT_MAX
// Uses strcmp and strlen to check if the number is 10 characters long and the
// difference from strcmp is greater than 1
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
bool	are_args_valid(char **argument_list, int *size)
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
