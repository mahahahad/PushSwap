/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:13 by maabdull          #+#    #+#             */
/*   Updated: 2023/11/07 13:25:05 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  print_str(const char *str)
{
  int i;

  i = 0;
  while (str[i])
    write(1, &str[i++], 1);
}

void  print_arr(const char **arr, int len)
{
  for (int i = 1; i < len; ++i) {
    print_str(arr[i]);
    print_str(" ");
  }
}

int	main(int argc, char const *argv[])
{
	(void)argv;
	if (argc == 1)
		return (0);
  print_arr(argv, argc);
	return (0);
}
