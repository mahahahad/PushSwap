/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:57 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 13:04:32 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Applies the function 'f' to the string 's' and creates a new string to
	// store this
/// @param s
	// The string to manipulate
/// @param f
	// The function to apply to each character
/// @return
	// The new string after manipulation
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*final_str;

	if (!s)
		return (NULL);
	i = -1;
	final_str = ft_strdup(s);
	if (!final_str)
		return (NULL);
	ft_bzero(final_str, ft_strlen(s));
	while (s[++i])
		final_str[i] = f(i, s[i]);
	return (final_str);
}
