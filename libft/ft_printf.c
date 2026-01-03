/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:12:27 by danielji          #+#    #+#             */
/*   Updated: 2025/05/19 16:28:02 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_putargument(char c, va_list	arg_ptr)
{
	if (c == '%')
		return (ft_putchar_r('%'));
	else if (c == 'c')
		return (ft_putchar_r(va_arg(arg_ptr, int)));
	else if (c == 's')
		return (ft_putstr_r(va_arg(arg_ptr, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_r(va_arg(arg_ptr, int)));
	else if (c == 'u')
		return (ft_putnbr_u_r(va_arg(arg_ptr, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_int_r(va_arg(arg_ptr, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex_int_r(va_arg(arg_ptr, int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putptr_r(va_arg(arg_ptr, void *)));
	else
		return (0);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	arg_ptr;
	ssize_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_putargument(str[i + 1], arg_ptr);
			i++;
		}
		else
		{
			count += ft_putchar_r(str[i]);
		}
		i++;
	}
	va_end(arg_ptr);
	return ((int)count);
}
