/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:18:29 by danielji          #+#    #+#             */
/*   Updated: 2025/11/24 15:21:24 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Output the character `c` to the specified file descriptor `fd`
and return the number of characters written */
ssize_t	ft_dputchar_r(int fd, char c)
{
	ssize_t	written;

	written = write(fd, &c, 1);
	return (written);
}

/* Output the string `s` to the specified file descriptor `fd`
and return the number of characters written */
ssize_t	ft_dputstr_r(int fd, char *s)
{
	ssize_t	written;

	written = 0;
	if (!s)
		written += write(fd, "(null)", 6);
	if (*s)
		written += write(fd, s, ft_strlen(s));
	return (written);
}

/* Output the unsigned integer `n` to the specified file descriptor `fd`
and return the number of characters written */
ssize_t	ft_dputnbr_u_r(int fd, unsigned int n)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (n / 10 > 0)
	{
		written += ft_dputnbr_u_r(fd, n / 10);
	}
	c = (n % 10) + '0';
	written += write(fd, &c, 1);
	return (written);
}

/* Output the integer `n` to the specified file descriptor `fd`
and return the number of characters written */
ssize_t	ft_dputnbr_r(int fd, int n)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (n == -2147483648)
	{
		written += write(fd, "-2147483648", 11);
		return (written);
	}
	if (n < 0)
	{
		written += write(fd, "-", 1);
		n = n * (-1);
	}
	if (n / 10 > 0)
	{
		written += ft_dputnbr_r(fd, n / 10);
	}
	c = (n % 10) + '0';
	written += write(fd, &c, 1);
	return (written);
}
