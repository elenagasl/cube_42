/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:57:16 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 21:42:56 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Write a number as hexadecimal.
`uintptr_t` is an `unsigned int` type designed to hold pointer values.
Base is passed as a string: `"0123456789abcdef"` or `"0123456789ABCDEF"`
Return number of characters written*/
static ssize_t	ft_puthex_r(uintptr_t num, char *base)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (num / 16 > 0)
		written += ft_puthex_r(num / 16, base);
	c = base[num % 16];
	written += write(1, &c, 1);
	return (written);
}

/* Write an unsigned int number as hexadecimal.
Return number of characters written */
ssize_t	ft_puthex_int_r(unsigned int num, char *base)
{
	return (ft_puthex_r((uintptr_t)num, base));
}

/* Write a pointer by calling `ft_puthex_r` or writing `0`.
Return number of characters written */
ssize_t	ft_putptr_r(void *ptr)
{
	ssize_t		written;
	uintptr_t	num;

	written = 0;
	if (!ptr)
	{
		written += write(1, "(nil)", 5);
		return (written);
	}
	num = (uintptr_t)ptr;
	written += write(1, "0x", 2);
	if (num == 0)
		written += write(1, "0", 1);
	else
		written += ft_puthex_r(num, "0123456789abcdef");
	return (written);
}
