/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:53:50 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 13:13:13 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/// @brief
	// Converts the character 'c' to a lowercase character if its an alphabet
/// @param c
	// The uppercase character to convert
/// @return
	// The lowercase character
int	ft_tolower(int c)
{
	if (isupper(c))
		return (c + 32);
	return (c);
}
