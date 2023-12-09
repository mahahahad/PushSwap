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
}

void	print_arr(const char **arr, int len)
{
	for (int i = 1; i < len; ++i)
	{
		print_str(arr[i]);
		print_str(" ");
	}
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

	// int	*stack_values;
	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			ft_split(argv[i], ' ');
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
