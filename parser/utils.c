/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:28:18 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 12:29:44 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Free an array of strings */
void	free_arr_str(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr);
	arr = NULL;
}

/* Initialize each integer in an array to passed `value` */
void	init_int_arr(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = value;
		i++;
	}
}

/* Close every open file descriptor in fd array `arr` */
void	close_fd_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] != -1)
		{
			close(arr[i]);
			arr[i] = -1;
		}
		i++;
	}
}
