/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:18:46 by danielji          #+#    #+#             */
/*   Updated: 2026/01/22 18:03:31 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Not exactly a flood fill algorithm, this function checks
whether a `0` is surrounded by a whitespace character */
int	flood_fill(char **arr, char p, int h)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (arr[y][x])
		{
			if ((arr[y][x] == '0' || arr[y][x] == p))
			{
				if (!is_surrounded(arr, y, x))
					return (printf(MAP_OPEN"\n"), 0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

/* A `0` can't be orthogonally surrounded by space */
int	is_surrounded(char **arr, int y, int x)
{
	if (ft_isspace(arr[y + 1][x]) ||
		ft_isspace(arr[y - 1][x]) ||
		ft_isspace(arr[y][x + 1]) ||
		ft_isspace(arr[y][x - 1]))
		return (0);
	return (1);
}
