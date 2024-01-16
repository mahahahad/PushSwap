/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:10:29 by maabdull          #+#    #+#             */
/*   Updated: 2023/12/27 15:44:27 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_list
{
	int		rank;
	int		data;
	char		stack_name;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

t_list	*rra(t_list *head);
t_list	*sa(t_list *head);
void	ra(t_list **head);
void	swap(t_list **head);
void	push(t_list **first_stack, t_list **second_stack);

#endif
