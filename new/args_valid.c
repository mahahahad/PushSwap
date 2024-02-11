/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:01:01 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/11 21:20:44 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Utility function that:
- Removes leading zeros
- Ignores signs
- Checks if the number is valid
- Returns false if invalid
- Returns true if valid

Makes it easier to pass the numbers into atoi
*/
bool	extract_num(char *num)
{
	int		i;

	i = 0;
	num += (*num == '+' || *num == '-');
	if (!(*num))
		return (false);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
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
		if (ft_atoi(num) == ft_atoi(arg_list[i]))
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

// Checks if the arguments contain long integers or duplicate values
void	check_long_dup_args(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		if (is_long(arguments[i]) || is_duplicate_string(arguments[i],
				arguments))
			return (free_args(arguments), show_err());
		i++;
	}
}
