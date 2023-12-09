/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:59:57 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 12:53:47 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Duplicates the string 'src' by allocating space for it into another
	// string
/// @param src
	// The string to duplicate
/// @return
	// The duplicated string
char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	src_len;

	src_len = ft_strlen(src) + 1;
	dup = malloc(src_len);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, src, src_len);
	return (dup);
}
