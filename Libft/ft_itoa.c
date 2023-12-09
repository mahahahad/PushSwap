/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:19:08 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 13:49:39 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n)
	{
		n /= 10;
		digits++;
	}
	if (!digits)
		digits = 1;
	return (digits);
}

static int	check_sign(int n, char *str)
{
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (!n)
		str[0] = '0';
	return (n);
}

static int	last_digit(int n)
{
	if (n < 0)
		return (0 - (n % 10));
	else
		return (n % 10);
}

/// @brief
	// Converts the integer 'n' into a string and returns it
/// @param n
	// The integer to convert
/// @return
	// The converted string value
char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		digits;

	digits = count_digits(n);
	i = digits;
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	n = check_sign(n, str);
	while (i-- && n)
	{
		str[i] = last_digit(n) + '0';
		n /= 10;
	}
	return (str);
}
