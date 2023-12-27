/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:10:29 by maabdull          #+#    #+#             */
/*   Updated: 2023/12/10 16:33:43 by maabdull         ###   ########.fr       */
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
	int		data;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

#endif
