/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 21:53:26 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 21:56:02 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Append string `str` to the end of array `arr`. Return new array. */
char	**ft_strappend(char **arr, char *str)
{
	int		i;
	int		size;
	char	**new_arr;

	if (!str)
		return (arr);
	i = 0;
	size = 0;
	while (arr && arr[size])
		size++;
	new_arr = malloc((size + 2) * sizeof(char *));
	if (!new_arr)
		return (NULL);
	while (i < size)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[size] = str;
	new_arr[size + 1] = NULL;
	free(arr);
	return (new_arr);
}
