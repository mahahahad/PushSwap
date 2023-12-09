/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:43:37 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 13:14:19 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/// @brief
	// Converts a lowercase character 'c' to an uppercase one if its an alphabet
/// @param c
	// The lowercase character to convert
/// @return
	// The uppercase character
int	ft_toupper(int c)
{
	if (islower(c))
		return (c - 32);
	return (c);
}
