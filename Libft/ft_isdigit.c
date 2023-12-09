/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:21:27 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 12:36:29 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Checks whether the character 'c' is a number
/// @param c
	// The character to check
/// @return
	// 1 if it is, 0 if it is not
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
