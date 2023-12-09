/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:58:30 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/23 14:47:26 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Locates the first occurence of char as int 'c' in a memory section 's'
	// within 'n' bytes
/// @param s
	// The memory location to search through
/// @param c
	// The character to look for
/// @param n
	// The number of iterations to use to find 'c'
/// @return
	// A pointer to this occurence or NULL if it is not found within 'n' bytes
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char) c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
