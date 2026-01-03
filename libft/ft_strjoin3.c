/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:45:16 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 21:41:58 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocate memory and return a new string, which is
the result of concatenating `str1`, `str2` and `str3`.*/
char	*ft_strjoin3(char *str1, char *str2, char *str3)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	len3 = ft_strlen(str3);
	str = malloc(len1 + len2 + len3 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, str1, len1);
	ft_memcpy(str + len1, str2, len2);
	ft_memcpy(str + len1 + len2, str3, len3);
	str[len1 + len2 + len3] = '\0';
	return (str);
}
