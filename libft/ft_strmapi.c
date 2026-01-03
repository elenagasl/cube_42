/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:54:09 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:54:43 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Apply the function `f` to each character of the string `s`, passing its
index as the first argument and the character itself as the second.
A new string is created to store the results from the successive applications
of `f`.*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;
	int		i;

	if (!f)
	{
		return ((void *)0);
	}
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return ((void *)0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
