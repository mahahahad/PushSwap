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
  char  *arguments;
  char  **argument_list;

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
  // Check duplicates and other things
  int x;

  x = 0;
  while (argument_list[x])
  {
    puts(argument_list[x]);
    x++;
  }
	return (0);
}
