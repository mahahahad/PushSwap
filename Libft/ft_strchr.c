/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:59:46 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/23 14:48:02 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Locates the first occurence of 'c' in the string 's'
/// @param s
	// The string to search through
/// @param c
	// The character to find
/// @return
	// The remaining part of the string with 'c' as the first character
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char) c)
			return ((char *) s + i);
	if (s[i] == c)
		return ((char *) s + i);
	return (0);
}
