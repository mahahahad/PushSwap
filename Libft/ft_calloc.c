/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:57:59 by maabdull          #+#    #+#             */
/*   Updated: 2023/12/10 16:49:45 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
// Dynamically allocate memory for 'count' elements with 'size' size
/// @param count
// The number of elements to allocate
/// @param size
// The size of each element
/// @return
// A void pointer to this newly allocated memory
void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if ((size * count) > SIZE_MAX)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
