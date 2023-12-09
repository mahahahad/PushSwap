/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:17:27 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 12:36:39 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/// @brief
	// Fills 'len' bytes of char 'c' into the string 'b'
/// @param b
	// The string to replace
/// @param c
	// The character to replace with
/// @param len
	// The number of characters to replace
/// @return
	// A pointer to this replaced string
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;
	size_t			i;

	i = 0;
	b_char = (unsigned char *) b;
	while (i != len)
		b_char[i++] = c;
	return (b = b_char);
}
