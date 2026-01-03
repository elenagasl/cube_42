/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:55:10 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:51:26 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Scan the initial `n` bytes of the memory area pointed to by `s` for the
first instance of `c`. Both `c` and the bytes of the memory area pointed to by
`s` are interpreted as `unsigned char`.
Return a pointer to the matching byte or `NULL` if the character does not
occur in the given memory area. */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	cc;

	cs = (unsigned char *)s;
	cc = (unsigned char)c;
	while (n--)
	{
		if (*cs == cc)
		{
			return (cs);
		}
		cs++;
	}
	return ((void *)0);
}
