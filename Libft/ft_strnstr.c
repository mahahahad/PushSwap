/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:00:26 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 13:06:04 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Locates the first occurence of the NULL-terminated string 'needle' in the
	// NULL-terminated string 'haystack'
/// @param haystack
	// The string to search in
/// @param needle
	// The string to search for
/// @return
	// If needle found: A pointer to the first character of the first
	// occurrence of it,
	// If needle is not found: A NULL pointer,
	// If needle is empty: The haystack
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*hay;

	i = -1;
	hay = (char *)haystack;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return (hay);
	while (hay[++i] && i < len)
	{
		j = 0;
		while (hay[i + j] && needle[j] && hay[i + j] == needle[j]
			&& i + j < len)
			j++;
		if (j == n_len)
			return (hay + i);
	}
	return (0);
}
