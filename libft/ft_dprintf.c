/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:12:27 by danielji          #+#    #+#             */
/*   Updated: 2025/11/24 13:24:10 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_dputargument(int fd, char c, va_list	arg_ptr)
{
	if (c == '%')
		return (ft_dputchar_r(fd, '%'));
	else if (c == 'c')
		return (ft_dputchar_r(fd, va_arg(arg_ptr, int)));
	else if (c == 's')
		return (ft_dputstr_r(fd, va_arg(arg_ptr, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_dputnbr_r(fd, va_arg(arg_ptr, int)));
	else if (c == 'u')
		return (ft_dputnbr_u_r(fd, va_arg(arg_ptr, unsigned int)));
	else if (c == 'x')
		return (ft_dputhex_ir(fd, va_arg(arg_ptr, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_dputhex_ir(fd, va_arg(arg_ptr, int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_dputptr_r(fd, va_arg(arg_ptr, void *)));
	else
		return (0);
}

int	ft_dprintf(int fd, char const *str, ...)
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
			count += ft_dputargument(fd, str[i + 1], arg_ptr);
			i++;
		}
		else
		{
			count += ft_dputchar_r(fd, str[i]);
		}
		i++;
	}
	va_end(arg_ptr);
	return ((int)count);
}
