/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:05:18 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:54:07 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Append the NULL-terminated string `src` to the end of `dst`.
It will append at most `size - strlen(dst) - 1` bytes, NULL-terminating the
result.
Return the total length of the string it tried to create, that means the
initial length of `dst` plus the length of `src`.*/
size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_i;
	size_t	src_i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dsize <= dst_len)
		return (dsize + src_len);
	dst_i = dst_len;
	src_i = 0;
	while (src[src_i] && (dst_i + src_i < dsize - 1))
	{
		dst[dst_i + src_i] = src[src_i];
		src_i++;
	}
	dst[dst_i + src_i] = '\0';
	return (dst_len + src_len);
}
