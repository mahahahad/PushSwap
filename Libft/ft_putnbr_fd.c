/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:52:01 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 12:37:19 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Write the number 'n' to the file descriptor 'fd'
/// @param n
	// The number to display
/// @param fd
	// The file descriptor to write to
void	ft_putnbr_fd(int n, int fd)
{
	char	result;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		result = '0' + (n % 10);
		write(fd, &result, 1);
	}
}
