/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:20:57 by danielji          #+#    #+#             */
/*   Updated: 2026/01/09 18:21:51 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Parse an array of strings into an array of integers */
int	map_to_int_arr(t_game *g, char **arr, char p)
{
	int	i;
	int	j;
	int	**map;

	map = allocate_map(g->map_w, g->map_h);
	if (!map)
		return (0);
	i = 0;
	while (i < g->map_h)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '1' || arr[i][j] == '0')
				map[i][j] = arr[i][j] - '0';
			else if (arr[i][j] == p)
				map[i][j] = 2;
			j++;
		}
		i++;
	}
	g->map = map;
	return (1);
}

/* Allocate memory for an array of arrays of integers.
Initialize every integer to `-1`.
If any allocation fails free every array and return `NULL` */
int	**allocate_map(int w, int h)
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

void	free_arr_int(int **arr, int size)
{
	if (!arr)
		return ;
	while (size)
		free(arr[--size]);
	free(arr);
	arr = NULL;
}
