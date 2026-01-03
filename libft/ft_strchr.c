/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:24:00 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:53:19 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return a pointer to the first occurrence of the character `c` in the
string `s` or `NULL` if the character is not found.
The terminating null byte is considered part of the string, so that if `c`
is specified as `'\0'`, it returns a pointer to the terminator.*/
char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return ((void *)0);
}
