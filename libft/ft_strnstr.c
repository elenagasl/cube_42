/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:53:00 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:55:32 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locate the first occurrence of the null-terminated string `little`
in the string `big`, where not more than `len` characters are searched.
Characters that appear after a `‘\0’` are not searched.
If `little` is an empty string, `big` is returned.
If `little` occurs nowhere in `big`, `NULL` is returned.
Return a pointer to the first character of the first occurrence of `little`. */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	if (little[0] == '\0')
		return ((char *)big);
	b = 0;
	while (big[b] && b <= len - 1)
	{
		l = 0;
		while (b + l < len && little[l] && big[b + l] == little[l])
		{
			l++;
		}
		if (little[l] == '\0')
		{
			return ((char *)&big[b]);
		}
		b++;
	}
	return ((void *)0);
}
