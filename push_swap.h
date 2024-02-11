/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:10:29 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/11 21:21:11 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				rank;
	int				data;
	char			stack_name;
	int				max;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void	rra(t_list **head);
void	ra(t_list **head);
void	swap(t_list **head);
void	push(t_list **first_stack, t_list **second_stack);
char	**process_args(char *argv[], int *size);
void	validate_args(char **arguments);
void	free_args(char **arguments);
void	show_err(void);
bool	extract_num(char *num);
void	check_long_dup_args(char **arguments);
t_list	*create_stack(char **arguments, int size);
t_list	*append_to_node(t_list *head, t_list *node);
t_list	*create_node(int num, int rank);
void	free_stack(t_list *stack);
void	print_list(t_list *stack);
bool	is_sorted(t_list *head, t_list *head_b);
t_list	**sort_three(t_list **head);
t_list	**sort_five(t_list **head_a, t_list **head_b, int size);
t_list	**sort_radix(t_list **head_a, t_list **head_b, int size);

#endif
