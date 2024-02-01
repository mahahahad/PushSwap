/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:05:24 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/01 21:07:51 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
// Checks if the character is a space character (>= 9 <= 13 || 32)
/// @param c The character to check
/// @return 1 if it is, 0 if it isn't
int	ft_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}
