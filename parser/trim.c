/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:04:09 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 09:36:53 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_trim_ws_left(char *str)
{
	char	*ptr;
	size_t	len;

	ptr = str;
	len = ft_strlen(ptr);
	if (len == 0)
		return ;
	while (*ptr && ft_isspace(*ptr))
	{
		len--;
		ptr++;
	}
	ft_memmove(str, ptr, len + 1);
}

void	ft_trim_ws_right(char *str)
{
	char	*ptr;
	size_t	len;

	ptr = str;
	len = ft_strlen(ptr);
	if (len == 0)
		return ;
	while (len > 0 && ft_isspace(ptr[len - 1]))
	{
		len--;
		ptr[len] = '\0';
	}
}

/* Trim leading & trailing whitespace in place */
void	ft_trim_whitespace(char *str)
{
	ft_trim_ws_right(str);
	ft_trim_ws_left(str);
}
