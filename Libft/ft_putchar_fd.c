/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:34:27 by maabdull          #+#    #+#             */
/*   Updated: 2023/07/20 12:36:41 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief
	// Write the character 'c' to the file descriptor 'fd'
/// @param c
	// The character to display
/// @param fd
	// The file descriptor to write to
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
