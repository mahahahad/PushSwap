/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:19:14 by maabdull          #+#    #+#             */
/*   Updated: 2024/02/01 21:07:43 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks if the character is a sign character or not
/// @param c The character to check
/// @return 1 if it is, 0 if it isn't
int	ft_issign(const char c)
{
	return (c == '+' || c == '-');
}