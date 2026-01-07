/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:23:59 by danielji          #+#    #+#             */
/*   Updated: 2026/01/07 14:58:34 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TODO: Save player position and orientation

/* Save map width and height into `t_game g`.
Spaces are taken into account, except for `\n` */
void	get_map_size(t_game *g, char **arr)
{
	int	i;
	int	width;
	int	max_width;

	i = 0;
	width = 0;
	max_width = 0;
	while (arr[i] && !is_empty_line(arr[i]))
	{
		width = ft_strlen(arr[i]) - 1;
		if (width > max_width)
			max_width = width;
		i++;
	}
	g->map_w = max_width;
	g->map_h = i;
}

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
		while (j < g->map_w)
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
If any allocation fails frree every array and return `NULL` */
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
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		init_int_arr(map[i], w, -1);
		i++;
	}
	return (map);
}
