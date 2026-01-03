/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:57:16 by danielji          #+#    #+#             */
/*   Updated: 2025/11/24 15:21:02 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Write a number as hexadecimal to the specified file descriptor `fd`.
`uintptr_t` is an `unsigned int` type designed to hold pointer values.
Base is passed as a string: `"0123456789abcdef"` or `"0123456789ABCDEF"`
Return number of characters written */
static ssize_t	ft_dputhex_r(int fd, uintptr_t num, char *base)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (num / 16 > 0)
		written += ft_dputhex_r(fd, num / 16, base);
	c = base[num % 16];
	written += write(fd, &c, 1);
	return (written);
}

/* Write an unsigned int number as hexadecimal to the specified file
descriptor `fd` and return the number of characters written */
ssize_t	ft_dputhex_ir(int fd, unsigned int num, char *base)
{
	return (ft_dputhex_r(fd, (uintptr_t)num, base));
}

/* Write a pointer by calling `ft_dputhex_r` or writing `(nil)`.
Return the number of characters written */
ssize_t	ft_dputptr_r(int fd, void *ptr)
{
	ssize_t		written;
	uintptr_t	num;

	written = 0;
	if (!ptr)
	{
		written += write(fd, "(nil)", 5);
		return (written);
	}
	num = (uintptr_t)ptr;
	written += write(fd, "0x", 2);
	if (num == 0)
		written += write(fd, "0", 1);
	else
		written += ft_dputhex_r(fd, num, "0123456789abcdef");
	return (written);
}
