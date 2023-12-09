/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:00:12 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 12:58:40 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Appends 'dstsize' of 'src' to 'dst' and NULL terminates
/// @param dst
	// The string to add to
/// @param src
	// The string to add from
/// @param dstsize
	// The number of bytes to copy
/// @return
	// The total length of the new string
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
	{
		while (src[j] && (dst_len + j) < dstsize)
			*(dst + i++) = *(src + j++);
		if ((dst_len + j) == dstsize && dst_len < dstsize)
			dst[i - 1] = '\0';
		else
			dst[i] = '\0';
		return (src_len + dst_len);
	}
}
