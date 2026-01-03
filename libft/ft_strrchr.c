/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:24:00 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:55:48 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return a pointer to the last occurrence of the character `c` in the
string `s`. Returns `NULL` if the character is not found.
The terminating null byte is considered part of the string, so that if
`c` is specified as `'\0'`, it returns a pointer to the terminator. */
char	*ft_strrchr(const char *str, int c)
{
	const char	*ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		ptr++;
	}
	while (ptr >= str)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((char *)ptr);
		}
		ptr--;
	}
	return ((void *)0);
}
