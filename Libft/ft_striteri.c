/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:00:04 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 13:04:04 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Applies the function 'f' to the original string 's' char by char
/// @param s
	// The string to manipulate
/// @param f
	// The function to apply with parameters unsigned int and char *
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (s)
	{
		i = -1;
		while (s[++i])
			f(i, &s[i]);
	}
}
