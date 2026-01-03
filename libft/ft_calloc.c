/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:36:44 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:48:27 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocate memory for an array of `nelem` elements of `size` bytes each and
return a pointer to the allocated memory. The memory is set to zero.
If `nelem` or `size` is 0, return a unique pointer value that can later be
successfully passed to free(). */
void	*ft_calloc(size_t nelem, size_t size)
{
	void	*arr;

	arr = malloc(nelem * size);
	if (!arr)
		return ((void *)0);
	ft_bzero(arr, nelem * size);
	return (arr);
}
