/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:04:09 by danielji          #+#    #+#             */
/*   Updated: 2026/01/06 11:28:17 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Trim leading whitespace in place */
void	trim_left_ws(char *str)
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

/* Trim trailing whitespace in place */
void	trim_right_ws(char *str)
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
void	trim_whitespace(char *str)
{
	trim_right_ws(str);
	trim_left_ws(str);
}
