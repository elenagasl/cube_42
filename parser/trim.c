/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:11:24 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 14:31:56 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Trim leading & trailing whitespace in place
Source: https://stackoverflow.com/a/123724 */
void	ft_trim_whitespace(char *str)
{
	char	*ptr;
	size_t	len;

	ptr = str;
	len = ft_strlen(ptr);
	if (len == 0)
		return ;
	while (ft_isspace(ptr[len - 1]))
	{
		len--;
		ptr[len] = '\0';
	}
	while (*ptr && ft_isspace(*ptr))
	{
		len--;
		ptr++;
	}
	ft_memmove(str, ptr, len + 1);
}
