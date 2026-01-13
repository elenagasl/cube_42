/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:20:57 by danielji          #+#    #+#             */
/*   Updated: 2026/01/14 00:09:55 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Allocate memory for an array of arrays of integers.
Initialize every integer to `-1`.
If any allocation fails free every array and return `NULL` */
static int	**allocate_map(int w, int h)
{
	int	i;
	int	**map;

	i = 0;
	map = malloc(h * sizeof(int *));
	if (!map)
		return (NULL);
	while (i < h)
	{
		map[i] = malloc(w * sizeof(int));
		if (!map[i])
			return (free_arr_int(map, i), NULL);
		init_int_arr(map[i], w, -1);
		i++;
	}
	return (map);
}

/* Parse an array of strings into an array of integers */
int	map_to_int_arr(t_game *g, char **arr, char p)
{
	int	y;
	int	x;
	int	**map;

	map = allocate_map(g->map_w, g->map_h);
	if (!map)
		return (0);
	y = 0;
	while (y < g->map_h)
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == '1' || arr[y][x] == '0')
				map[y][x] = arr[y][x] - '0';
			else if (arr[y][x] == p)
				map[y][x] = 0;
			x++;
		}
		y++;
	}
	g->map = map;
	return (1);
}
