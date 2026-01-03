/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:36:59 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:53:26 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return a pointer to a new string which is a duplicate of the string `s`
or `NULL` if insufficient memory was available */
char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	if (!str)
		return ((void *)0);
	i = 0;
	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return ((void *)0);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
