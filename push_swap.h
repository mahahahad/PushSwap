/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:10:29 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/09 23:50:32 by maabdull         ###   ########.fr       */
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
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*rra(t_list *head);
t_list				*sa(t_list *head);
void				ra(t_list **head);
void				swap(t_list **head);
void				push(t_list **first_stack, t_list **second_stack);
bool				are_args_valid(char **argument_list, int *size);
char	**process_args(char *argv[], int *size);
char	**validate_args(char **arguments);
void	free_args(char **arguments);

#endif
