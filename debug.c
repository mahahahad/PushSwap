/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:13:16 by maabdull          #+#    #+#             */
/*   Updated: 2024/01/22 17:22:09 by maabdull         ###   ########.fr       */
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
void	print_int_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d", arr[i]);
		if (i + 1 != size)
			printf(", ");
		i++;
	}
	puts("");
}
