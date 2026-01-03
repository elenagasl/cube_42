/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:18:29 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 21:42:57 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Output the character `c` and return number of characters written */
ssize_t	ft_putchar_r(char c)
{
	ssize_t	written;

	written = write(1, &c, 1);
	return (written);
}

/* Output the string `s` and return number of characters written.*/
ssize_t	ft_putstr_r(char *s)
{
	ssize_t	written;

	written = 0;
	if (!s)
		written += write(1, "(null)", 6);
	while (s && *s)
	{
		written += write(1, s, 1);
		s++;
	}
	return (written);
}

/* Output the unsigned integer `n` and return number of characters written */
ssize_t	ft_putnbr_u_r(unsigned int n)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (n / 10 > 0)
	{
		written += ft_putnbr_u_r(n / 10);
	}
	c = (n % 10) + '0';
	written += write(1, &c, 1);
	return (written);
}

/* Output the integer `n` and return number of characters written */
ssize_t	ft_putnbr_r(int n)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (n == -2147483648)
	{
		written += write(1, "-2147483648", 11);
		return (written);
	}
	if (n < 0)
	{
		written += write(1, "-", 1);
		n = n * (-1);
	}
	if (n / 10 > 0)
	{
		written += ft_putnbr_r(n / 10);
	}
	c = (n % 10) + '0';
	written += write(1, &c, 1);
	return (written);
}
