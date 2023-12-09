/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:33:56 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 12:36:12 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Checks whether the character 'c' is a digit or an alphabet
/// @param c
	// The character to check
/// @return
	// 1 if it is, 0 if it is not
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
