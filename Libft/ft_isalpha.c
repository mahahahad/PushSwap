/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:24:06 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 12:36:22 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/// @brief
	// Checks whether the character 'c' is an alphabet. This is done by
	// checking if its either an uppercase letter or a lowercase letter.
/// @param c
	// The character to check
/// @return
	// 1 if it is, 0 if it is not
int	ft_isalpha(int c)
{
	return ((ft_islower(c) || ft_isupper(c)));
}
